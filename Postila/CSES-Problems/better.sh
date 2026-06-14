#!/usr/bin/env bash
set -euo pipefail

# Usage: ./cses_to_pdf_with_toc.sh list.txt output.pdf
# list.txt example:
# Graph
# 1192 - Counting Rooms
# 1193 - Labyrinth
# 1666 - Building Roads

INPUT_FILE="${1:-}"
OUT_PDF="${2:-cses_tasks.pdf}"

if [[ -z "$INPUT_FILE" || ! -f "$INPUT_FILE" ]]; then
  cat >&2 <<EOF
Usage: $0 list.txt [output.pdf]
 - list.txt must exist and contain a topic title followed by problem lines
EOF
  exit 2
fi

# Read the first line as the topic title
TOPIC_TITLE=$(head -n 1 "$INPUT_FILE" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
echo "Topic: $TOPIC_TITLE"

# Build ordered list of (num, title) from file (skip first line)
declare -a nums
declare -a titles
declare -a has_solution

# Skip first line and process the rest
line_number=0
while IFS= read -r line || [[ -n $line ]]; do
  line_number=$((line_number + 1))
  # Skip first line (topic title)
  if [[ $line_number -eq 1 ]]; then
    continue
  fi
  
  # Skip empty lines
  if [[ -z "$(echo "$line" | tr -d '[:space:]')" ]]; then
    continue
  fi

  # extract leading number (first number on the line)
  if [[ $line =~ ^[[:space:]]*([0-9]+)[[:space:]]*-(.*)$ ]]; then
    num="${BASH_REMATCH[1]}"
    title="$(printf '%s' "${BASH_REMATCH[2]}" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')"
  else
    # try any leading number
    num=$(printf '%s' "$line" | sed -E 's/^[[:space:]]*([0-9]+).*/\1/')
    title="$(printf '%s' "$line" | sed 's/^[[:space:]]*[0-9]*[[:space:]]*//')"
  fi
  
  if [[ -n "$num" && "$num" =~ ^[0-9]+$ ]]; then
    nums+=("$num")
    titles+=("$title")
    
    # Check if solution file exists in CSES-Solutions/{topic_title}/{problem_title}.cpp
    solution_file="CSES-Solutions/${TOPIC_TITLE}/${title}.cpp"
    if [[ -f "$solution_file" ]]; then
      has_solution+=(1)
      echo "Found solution: $solution_file"
    else
      has_solution+=(0)
      echo "No solution found: $solution_file"
    fi
  fi
done < "$INPUT_FILE"

if [[ ${#nums[@]} -eq 0 ]]; then
  echo "No task numbers found in $INPUT_FILE" >&2
  exit 3
fi

echo "Found ${#nums[@]} tasks. Creating PDF: $OUT_PDF"

# temporary dir
TMPDIR=$(mktemp -d)
trap 'rm -rf "$TMPDIR"' EXIT

# find chrome binary
BROWSER_BIN=""
for b in brave-browser brave-browser-stable brave chromium google-chrome chrome; do
  if command -v "$b" >/dev/null 2>&1; then
    BROWSER_BIN=$(command -v "$b")
    break
  fi
done

if [[ -z "$BROWSER_BIN" ]]; then
  echo "No Chromium/Chrome binary found. Install chromium/google-chrome/brave." >&2
  exit 4
fi

echo "Using headless Chrome: $BROWSER_BIN"

pdf_files=()

# 1) Create a tiny TOC HTML and print it first
TOC_HTML="$TMPDIR/toc.html"
cat > "$TOC_HTML" <<HTML
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>CSES Tasks — Table of Contents</title>
<style>
body { font-family: sans-serif; max-width:900px; margin: 2rem auto; }
h1 { font-size: 1.4rem; margin-bottom: .5rem; }
h2 { font-size: 1.2rem; margin: 1rem 0 0.5rem 0; color: #333; }
ol { padding-left: 1.2rem; }
li { margin: .4rem 0; line-height:1.2; }
.small { color: #666; font-size: .95rem; }
.no-solution { color: #999; font-style: italic; }
</style>
</head>
<body>
<h1>Table of Contents</h1>
<h2>${TOPIC_TITLE}</h2>
<ol>
HTML

# append items
for i in "${!nums[@]}"; do
  n="${nums[$i]}"
  t="${titles[$i]}"
  # escape HTML entities lightly
  esc_title=$(printf '%s' "$t" | sed 's/&/\&amp;/g; s/</\&lt;/g; s/>/\&gt;/g')
  
  if [[ ${has_solution[$i]} -eq 1 ]]; then
    echo "  <li><span class=\"small\">${n}</span> — ${esc_title}</li>" >> "$TOC_HTML"
  else
    echo "  <li><span class=\"small\">${n}</span> — <span class=\"no-solution\">${esc_title} (no solution found)</span></li>" >> "$TOC_HTML"
  fi
done

cat >> "$TOC_HTML" <<'HTML'
</ol>
</body>
</html>
HTML

TOC_PDF="$TMPDIR/000_toc.pdf"
echo "Printing TOC -> $TOC_PDF"
# window-size 900 width so PDF content width matches our target
"$BROWSER_BIN" --headless --disable-gpu --no-sandbox \
  --print-to-pdf="$TOC_PDF" \
  --virtual-time-budget=8000 \
  --window-size=900,1200 \
  "file://$TOC_HTML"

if [[ ! -f "$TOC_PDF" ]]; then
  echo "Failed to create TOC PDF." >&2
  exit 5
fi
pdf_files+=("$TOC_PDF")

# helper: CSS to inject into downloaded pages to hide header/sidebar and constrain width
INJECTED_CSS='<style>
/* best-effort hide header/sidebar and constrain width for print */
header, #header, .header, .site-header, .topbar, #topbar, .navbar, .sidebar, #sidebar, aside, .right { display:none !important; }
body { max-width:900px !important; margin: 0 auto !important; padding-top: 0 !important; }
@media print { body { width:900px; } }
</style>'

# For each task: download a local copy, inject CSS, print local file
i=0
for idx_num in "${!nums[@]}"; do
  n="${nums[$idx_num]}"
  t="${titles[$idx_num]}"
  
  # Skip if no solution exists
  if [[ ${has_solution[$idx_num]} -eq 0 ]]; then
    echo "Skipping $n - $t (no solution)"
    i=$((i+1))
    continue
  fi
  
  idx=$(printf "%03d" "$i")
  out_pdf="$TMPDIR/page_${idx}.pdf"
  page_dir="$TMPDIR/page_${idx}_files"
  url="https://cses.fi/problemset/task/${n}/"

  echo "Downloading $url into $page_dir"
  mkdir -p "$page_dir"

  # wget: -p (page requisites), -k (convert links), -E (add .html), -nd not used so resources go into page_dir
  if ! wget -q -E -H -k -p -P "$page_dir" "$url"; then
    echo "wget failed for $url — attempting direct print of the remote URL instead"
    # fallback: directly print remote URL (still with window-size 900)
    "$BROWSER_BIN" --headless --disable-gpu --no-sandbox \
      --print-to-pdf="$out_pdf" \
      --virtual-time-budget=12000 \
      --window-size=900,1600 \
      "$url"
    if [[ ! -f "$out_pdf" ]]; then
      echo "Failed to create PDF for $url" >&2
      exit 6
    fi
    pdf_files+=("$out_pdf")
    i=$((i+1))
    continue
  fi

  # find the main HTML file that wget saved
  # common names: index.html or the url path -> use the first .html found
  htmlfile=$(find "$page_dir" -type f -iname "*.html" | head -n1 || true)
  if [[ -z "$htmlfile" ]]; then
    # fallback to printing remote
    echo "Could not find downloaded HTML for $url — printing remote URL"
    "$BROWSER_BIN" --headless --disable-gpu --no-sandbox \
      --print-to-pdf="$out_pdf" \
      --virtual-time-budget=12000 \
      --window-size=900,1600 \
      "$url"
    if [[ ! -f "$out_pdf" ]]; then
      echo "Failed to create PDF for $url" >&2
      exit 7
    fi
    pdf_files+=("$out_pdf")
    i=$((i+1))
    continue
  fi

  # inject CSS before </head> (best-effort)
  # use awk to insert INJECTED_CSS before the closing </head>
  awk -v inj="$INJECTED_CSS" 'BEGIN{IGNORECASE=1} { if(!done && tolower($0) ~ /<\/head>/){ print inj; done=1 } print }' "$htmlfile" > "${htmlfile}.injected" && mv "${htmlfile}.injected" "$htmlfile"

  # Print local file with 900px viewport to avoid showing right sidebar
  echo "Printing [$((i+1))/${#nums[@]}] file://$htmlfile -> $out_pdf"
  "$BROWSER_BIN" --headless --disable-gpu --no-sandbox \
    --print-to-pdf="$out_pdf" \
    --virtual-time-budget=10000 \
    --window-size=900,1600 \
    "file://$htmlfile"

  if [[ ! -f "$out_pdf" ]]; then
    echo "Failed to create $out_pdf for $url" >&2
    exit 8
  fi

  pdf_files+=("$out_pdf")
  i=$((i+1))
done

# Merge PDFs: prefer pdfunite, fallback to ghostscript (gs)
if command -v pdfunite >/dev/null 2>&1; then
  echo "Merging PDFs with pdfunite..."
  pdfunite "${pdf_files[@]}" "$OUT_PDF"
  echo "Done -> $OUT_PDF"
  exit 0
elif command -v gs >/dev/null 2>&1; then
  echo "Merging PDFs with ghostscript..."
  gs -q -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile="$OUT_PDF" "${pdf_files[@]}"
  echo "Done -> $OUT_PDF"
  exit 0
else
  echo "Could not find pdfunite or ghostscript to merge the temporary PDFs." >&2
  echo "Temporary PDFs are in $TMPDIR" >&2
  echo "Install poppler-utils (pdfunite) or ghostscript (gs) and rerun the merge:" >&2
  echo "  pdfunite \"$TMPDIR\"/page_*.pdf \"$OUT_PDF\"" >&2
  exit 9
fi
