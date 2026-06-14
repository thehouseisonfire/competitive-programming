#!/usr/bin/env bash
set -euo pipefail

# merge-with-toc.sh
# Usage: ./merge-with-toc.sh order.txt [output.pdf]
# - order.txt contains one PDF filename per line (can include spaces)
# - output.pdf defaults to merged.pdf

ORDER_FILE="${1:-order.txt}"
OUT_PDF="${2:-merged.pdf}"
TMPDIR="$(mktemp -d)"
cleanup() { rm -rf "$TMPDIR"; }
trap cleanup EXIT

# --- Check dependencies (we only require at least one merging tool and one page-counter + one TOC-generator) ---
have_cmd() { command -v "$1" >/dev/null 2>&1; }

# Prefer pdfinfo for page counts; fallback to qpdf
PAGECOUNT_TOOL=""
if have_cmd pdfinfo; then
  PAGECOUNT_TOOL="pdfinfo"
elif have_cmd qpdf; then
  PAGECOUNT_TOOL="qpdf"
else
  echo "Error: need 'pdfinfo' or 'qpdf' to read PDF page counts." >&2
  echo "Please install poppler-utils (pdfinfo) or qpdf." >&2
  exit 1
fi

# TOC -> PDF: prefer enscript + ps2pdf (ghostscript). fallback: wkhtmltopdf if user has it.
TOC_TOOL=""
if have_cmd enscript && have_cmd ps2pdf; then
  TOC_TOOL="enscript"
elif have_cmd wkhtmltopdf; then
  TOC_TOOL="wkhtmltopdf"
else
  echo "Error: need 'enscript' + 'ps2pdf' or 'wkhtmltopdf' to create the TOC PDF." >&2
  echo "Install enscript and ghostscript (ps2pdf) or wkhtmltopdf." >&2
  exit 1
fi

# Merging tools: try pdfunite, then qpdf, then ghostscript (gs)
MERGER=""
if have_cmd pdfunite; then
  MERGER="pdfunite"
elif have_cmd qpdf; then
  MERGER="qpdf"
elif have_cmd gs; then
  MERGER="gs"
else
  echo "Error: need one of pdfunite / qpdf / gs to merge PDFs." >&2
  exit 1
fi

# --- Read order file and validate ---
if [[ ! -f "$ORDER_FILE" ]]; then
  echo "Error: order file '$ORDER_FILE' not found." >&2
  exit 1
fi

mapfile -t FILES < <(sed -n 's/^[[:space:]]*//;s/[[:space:]]*$//;/^$/d;p' "$ORDER_FILE")

if (( ${#FILES[@]} == 0 )); then
  echo "Error: no files listed in '$ORDER_FILE'." >&2
  exit 1
fi

# Expand relative paths and check existence; preserve original order
for f in "${FILES[@]}"; do
  if [[ ! -f "$f" ]]; then
    echo "Error: listed file does not exist: '$f'." >&2
    exit 1
  fi
done

# --- Helper: get page count for a PDF ---
get_page_count() {
  local file="$1"
  if [[ "$PAGECOUNT_TOOL" == "pdfinfo" ]]; then
    # pdfinfo output: Pages: N
    pdfinfo "$file" 2>/dev/null | awk '/^Pages:/ {print $2}'
  else
    # qpdf --show-npages
    qpdf --show-npages "$file" 2>/dev/null
  fi
}

# --- Build arrays of page counts ---
declare -a PAGES
for f in "${FILES[@]}"; do
  p=$(get_page_count "$f" || true)
  if ! [[ "$p" =~ ^[0-9]+$ ]]; then
    echo "Error: couldn't determine page count for '$f'." >&2
    exit 1
  fi
  PAGES+=("$p")
done

# --- Create TOC text given a presumed number of TOC pages ---
generate_toc_text() {
  local toc_pages_assumed=$1
  local toc_txt="$TMPDIR/toc.txt"
  : > "$toc_txt"
  printf "%s\n\n" "Table of Contents" >> "$toc_txt"
  printf "%s\n\n" "------------------------" >> "$toc_txt"

  local start=$((toc_pages_assumed + 1))
  local i=0
  for f in "${FILES[@]}"; do
    title="$(basename "${f%.*}")"
    # Replace underscores with spaces
    title="${title//_/ }"
    # Format: title ................................ page
    # Make a fixed width column for title; the printf below aligns.
    printf "%-70s %5d\n" "$title" "$start" >> "$toc_txt"
    start=$((start + PAGES[i]))
    ((i++))
  done

  echo "$toc_txt"
}

# --- Convert TOC text to PDF and return number of pages ---
toc_text_to_pdf_and_count() {
  local toc_txt="$1"
  local out_pdf="$2"
  if [[ "$TOC_TOOL" == "enscript" ]]; then
    # Use A4 by default; adjust font size if needed.
    # -B: no header/footer, --media=A4
    enscript --media=A4 -B -f "Times-Roman20" -o - "$toc_txt" 2>/dev/null | ps2pdf - "$out_pdf"
  else
    # wkhtmltopdf path: produce an HTML and render it
    html="$TMPDIR/toc.html"
    echo "<html><head><meta charset='utf-8'><style>body{font-family:serif; font-size:20pt; margin:0.25in}</style></head><body><pre>$(sed 's/&/\&amp;/g; s/</\&lt;/g; s/>/\&gt;/g' "$toc_txt")</pre></body></html>" > "$html"
    wkhtmltopdf --page-size A4 "$html" "$out_pdf"
  fi

  # count pages
  get_page_count "$out_pdf"
}

# --- Iterate until TOC page count stabilizes (usually 1-2 iterations) ---
toc_pages=1
for iter in 1 2 3 4 5; do
  toc_txt="$(generate_toc_text "$toc_pages")"
  toc_pdf="$TMPDIR/toc.pdf"
  newtocpages="$(toc_text_to_pdf_and_count "$toc_txt" "$toc_pdf")"
  if [[ -z "$newtocpages" || ! "$newtocpages" =~ ^[0-9]+$ ]]; then
    echo "Error: failed to create TOC PDF or count its pages." >&2
    exit 1
  fi
  if (( newtocpages == toc_pages )); then
    echo "TOC pages stabilized at $toc_pages (after $iter iterations)."
    break
  fi
  toc_pages=$newtocpages
  if (( iter == 5 )); then
    echo "Warning: TOC page count didn't stabilize after 5 iterations; using $toc_pages." >&2
  fi
done

# Final TOC (regenerate once more to ensure content matches final toc_pages)
toc_txt="$(generate_toc_text "$toc_pages")"
toc_pdf="$TMPDIR/toc.pdf"
toc_text_to_pdf_and_count "$toc_txt" "$toc_pdf" >/dev/null

# --- Merge TOC + all files into the output PDF ---
echo "Merging files into '$OUT_PDF'..."

case "$MERGER" in
  pdfunite)
    # Order: toc.pdf then the listed files in same order
    pdfunite "$toc_pdf" "${FILES[@]}" "$OUT_PDF"
    ;;
  qpdf)
    # qpdf --empty --pages a.pdf b.pdf c.pdf -- out.pdf
    qpdf --empty --pages "$toc_pdf" "${FILES[@]}" -- "$OUT_PDF"
    ;;
  gs)
    # ghostscript merging
    gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile="$OUT_PDF" "$toc_pdf" "${FILES[@]}"
    ;;
  *)
    echo "Error: unknown merger '$MERGER'." >&2
    exit 1
    ;;
esac

echo "Done. Output: $OUT_PDF"
