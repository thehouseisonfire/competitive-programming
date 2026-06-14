#!/usr/bin/env bash
set -euo pipefail

# Usage: ./cses_to_pdf.sh list.txt output.pdf
# list.txt example lines:
# 1068 - Weird Algorithm
# 1083 - Missing Number
# ...

INPUT_FILE="${1:-}"
OUT_PDF="${2:-cses_tasks.pdf}"

if [[ -z "$INPUT_FILE" || ! -f "$INPUT_FILE" ]]; then
  cat >&2 <<EOF
Usage: $0 list.txt [output.pdf]
 - list.txt must exist and contain lines starting with the task number (e.g. "1068 - Weird Algorithm")
EOF
  exit 2
fi

# Build ordered list of urls from file (preserve order, skip blank/non-number lines)
urls=()
while IFS= read -r line || [[ -n $line ]]; do
  # extract leading number (first number on the line)
  num=$(printf '%s' "$line" | sed -E 's/^[[:space:]]*([0-9]+).*/\1/')
  if [[ -n "$num" && "$num" =~ ^[0-9]+$ ]]; then
    # include trailing slash to avoid redirect issues
    urls+=("https://cses.fi/problemset/task/${num}/")
  fi
done < "$INPUT_FILE"

if [[ ${#urls[@]} -eq 0 ]]; then
  echo "No task numbers found in $INPUT_FILE" >&2
  exit 3
fi

echo "Found ${#urls[@]} tasks. Creating PDF: $OUT_PDF"

# Option 1: use wkhtmltopdf (single command supports multiple URLs in order)
# if command -v wkhtmltopdf >/dev/null 2>&1; then
#   echo "Using wkhtmltopdf..."
#   # set a friendly user agent (some sites block unknown UA); allow some JS time
#   UA="Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120 Safari/537.36"
#   # --javascript-delay gives pages time to load (ms). Adjust if some pages load slowly.
#   wkhtmltopdf --custom-header "User-Agent" "$UA" --javascript-delay 1200 --no-stop-slow-scripts --quiet "${urls[@]}" "$OUT_PDF"
#   echo "Done -> $OUT_PDF"
#   exit 0
# fi

# Option 2: fallback to headless Chrome/Chromium + merge
# create temp dir
TMPDIR=$(mktemp -d)
trap 'rm -rf "$TMPDIR"' EXIT

# find chrome binary
BROWSER_BIN=""
for b in brave chromium-browser chromium google-chrome chrome; do
  if command -v "$b" >/dev/null 2>&1; then
    BROWSER_BIN=$(command -v "$b")
    break
  fi
done

if [[ -z "$BROWSER_BIN" ]]; then
  echo "Neither wkhtmltopdf nor a Chromium/Chrome binary was found." >&2
  echo "Install wkhtmltopdf (recommended) or chromium/google-chrome." >&2
  exit 4
fi

echo "Using headless Chrome: $BROWSER_BIN"
pdf_files=()
i=0
for u in "${urls[@]}"; do
  idx=$(printf "%03d" "$i")
  out="$TMPDIR/page_${idx}.pdf"
  echo "Printing [$((i+1))/${#urls[@]}] $u -> $out"
  # print-to-pdf requires a file path; headless print may not wait for async loads,
  # virtual-time-budget increases wait time. Increase if pages need more time.
  "$BROWSER_BIN" \
    --headless --disable-gpu --no-sandbox \
    --print-to-pdf="$out" \
    --virtual-time-budget=3000 \
    "$u"
  if [[ ! -f "$out" ]]; then
    echo "Failed to create $out for $u" >&2
    exit 5
  fi
  pdf_files+=("$out")
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
  exit 6
fi
