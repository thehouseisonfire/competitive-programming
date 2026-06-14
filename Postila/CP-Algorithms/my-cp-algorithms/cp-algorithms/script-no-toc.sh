#!/usr/bin/env bash
set -euo pipefail

# Usage: ./html_list_to_pdf.sh input.html output.pdf
# Input HTML should contain a nested list structure with <a> tags

INPUT_FILE="${1:-}"
OUT_PDF="${2:-cses_tasks.pdf}"

if [[ -z "$INPUT_FILE" || ! -f "$INPUT_FILE" ]]; then
  cat >&2 <<EOF
Usage: $0 input.html [output.pdf]
 - input.html must exist and contain a nested list structure with <a> tags
EOF
  exit 2
fi

# Extract all href paths from the HTML list
declare -a paths
declare -a titles

# Use xmllint if available, or fallback to grep/sed
if command -v xmllint >/dev/null 2>&1; then
  echo "Using xmllint to parse HTML..."
  # Extract all href attributes from <a> tags
  while IFS= read -r href; do
    if [[ -n "$href" ]]; then
      paths+=("$href")
    fi
  done < <(xmllint --html --xpath '//a/@href' "$INPUT_FILE" 2>/dev/null | sed 's/href="\([^"]*\)"/\1/g' | tr ' ' '\n' | grep -v '^$')

  # Extract all link text from <a> tags
  while IFS= read -r title; do
    if [[ -n "$title" ]]; then
      titles+=("$title")
    fi
  done < <(xmllint --html --xpath '//a/text()' "$INPUT_FILE" 2>/dev/null | tr '|' '\n' | sed 's/^[[:space:]]*//;s/[[:space:]]*$//' | grep -v '^$')
else
  echo "Using grep/sed to parse HTML (install xmllint for better parsing)..."
  # Fallback method using grep/sed
  while IFS= read -r line; do
    if [[ $line =~ href=\"([^\"]+)\" ]]; then
      paths+=("${BASH_REMATCH[1]}")
    fi
  done < <(grep -o '<a[^>]*href="[^"]*"[^>]*>' "$INPUT_FILE")

  while IFS= read -r line; do
    if [[ $line =~ \<a[^\>]*\>([^<]+)\</a\> ]]; then
      titles+=("${BASH_REMATCH[1]}")
    fi
  done < <(grep -o '<a[^>]*>[^<]*</a>' "$INPUT_FILE")
fi

# If titles array is empty or doesn't match paths, try alternative approach
if [[ ${#titles[@]} -ne ${#paths[@]} ]] || [[ ${#titles[@]} -eq 0 ]]; then
  echo "Warning: Could not extract titles properly, using filenames as titles"
  titles=()
  for path in "${paths[@]}"; do
    # Extract filename without extension for title
    filename=$(basename "$path" .html)
    # Convert hyphens to spaces and capitalize
    title=$(echo "$filename" | sed 's/-/ /g' | sed 's/\b\(.\)/\u\1/g')
    titles+=("$title")
  done
fi

if [[ ${#paths[@]} -eq 0 ]]; then
  echo "No href links found in $INPUT_FILE" >&2
  exit 3
fi

echo "Found ${#paths[@]} links. Creating PDF: $OUT_PDF"

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

# helper: CSS to inject into downloaded pages to hide header/sidebar and constrain width
INJECTED_CSS='<style>
/* Hide headers, sidebars, practice problems section, and constrain width for clean print layout */
header, #header, .header, .site-header, .topbar, #topbar, .navbar, .sidebar, #sidebar, aside, .right,
#practice-problems, #practice-problems + ul, #practice-problems + ul + ul.metadata.page-metadata { display:none !important; }
html { max-width:900px !important; margin: 0 auto !important; padding-top: 0 !important; font-size: 2rem !important; }
@media print { body { width:900px; } }
</style>'

# For each page: download a local copy, inject CSS, print local file
i=0
for path in "${paths[@]}"; do
  idx=$(printf "%03d" "$i")
  out_pdf="$TMPDIR/page_${idx}.pdf"
  page_dir="$TMPDIR/page_${idx}_files"
  
  # Construct full URL (assuming localhost:8000 as base)
  url="http://localhost:8000/${path}"

  echo "Downloading $url into $page_dir"
  mkdir -p "$page_dir"

 # wget: -p (page requisites), -k (convert links), -E (add .html)
  # Use timeouts and force IPv4 to avoid long hangs on some localhost setups.
  # Also set a browser-like User-Agent so some dev servers don't block the request.
  UA='Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Brave/1.0'
  WGET_LOG="$page_dir/wget.log"
  CURL_LOG="$page_dir/curl.log"

  # Try wget first (fetch page requisites). Prefer IPv4 and short timeouts so we don't hang.
  if ! wget -o "$WGET_LOG" -q --inet4-only --tries=2 --timeout=20 --dns-timeout=10 --connect-timeout=10 \
           -E -H -k -p -P "$page_dir" --header="User-Agent: $UA" "$url"; then
    echo "wget failed for $url — check $WGET_LOG. Attempting lighter curl fetch of main HTML..."

    # Try curl to get at least the main HTML quickly (use IPv4, limited time).
    # This won't fetch requisites, but gives us an HTML file to inject CSS into and print.
    if ! curl --ipv4 -L --max-time 20 -sS -A "$UA" -o "$page_dir/raw.html" "$url" 2> "$CURL_LOG"; then
      echo "curl also failed for $url — check $CURL_LOG. Falling back to direct remote printing."
      # fallback: directly print remote URL (still with window-size 900)
      "$BROWSER_BIN" --headless --disable-gpu --no-sandbox \
        --print-to-pdf="$out_pdf" \
        --virtual-time-budget=12000 \
        --window-size=900,1600 \
        "$url"
      if [[ ! -f "$out_pdf" ]]; then
        echo "Failed to create PDF for $url" >&2
        echo "wget log: $WGET_LOG" >&2
        echo "curl log: $CURL_LOG" >&2
        exit 6
      fi
      pdf_files+=("$out_pdf")
      i=$((i+1))
      continue
    fi
  fi

  # find the main HTML file that wget saved (or the curl fallback raw.html)
  htmlfile=$(find "$page_dir" -type f -iname "*.html" | head -n1 || true)
  if [[ -z "$htmlfile" && -f "$page_dir/raw.html" ]]; then
    htmlfile="$page_dir/raw.html"
  fi

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
  echo "Printing [$((i+1))/${#paths[@]}] file://$htmlfile -> $out_pdf"
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
