#!/usr/bin/env bash
set -euo pipefail

# --- USAGE ---
# ./solutions_to_pdf.sh <problem-list.txt> <output.pdf> <solutions-directory>
#
# Example:
# ./solutions_to_pdf.sh introductory.txt introductory-solutions.pdf "Introductory Problems/"
#
# <problem-list.txt>: File with lines like "1068 - Weird Algorithm"
# <output.pdf>: The final merged PDF file to create.
# <solutions-directory>: The path to the directory containing the .cpp files.
# ---

# --- DEPENDENCIES ---
# 1. A Chromium-based browser (Chrome, Brave, Chromium) for printing to PDF.
# 2. 'pdfunite' (from poppler-utils) or 'gs' (Ghostscript) for merging PDFs.
#     On Debian/Ubuntu: sudo apt-get install poppler-utils ghostscript
# ---

INPUT_FILE="${1:-}"
OUT_PDF="${2:-cses_solutions.pdf}"
SOLUTIONS_DIR="${3:-}"

# --- Argument Validation ---
if [[ -z "$INPUT_FILE" || ! -f "$INPUT_FILE" || -z "$OUT_PDF" || -z "$SOLUTIONS_DIR" || ! -d "$SOLUTIONS_DIR" ]]; then
    cat >&2 <<EOF
Usage: $0 list.txt output.pdf solutions_directory/

  - list.txt: Must be a file containing lines like "1068 - Weird Algorithm".
  - output.pdf: The PDF file you want to create.
  - solutions_directory/: Must be an existing directory containing your .cpp solutions.
EOF
    exit 2
fi

# --- Find Browser ---
BROWSER_BIN=""
for b in brave-browser brave-browser-stable brave chromium google-chrome chrome; do
    if command -v "$b" >/dev/null 2>&1; then
        BROWSER_BIN=$(command -v "$b")
        break
    fi
done
if [[ -z "$BROWSER_BIN" ]]; then
    echo "Error: No Chromium/Chrome binary found. Please install chromium, google-chrome, or brave." >&2
    exit 4
fi
echo "Using headless browser: $BROWSER_BIN"

# --- Setup Temporary Directory ---
TMPDIR=$(mktemp -d)
trap 'rm -rf "$TMPDIR"' EXIT

MAIN_TITLE=$(head -n 1 "$INPUT_FILE")
tail -n +2 "$INPUT_FILE" > "$TMPDIR"/_temp_list.txt

declare -a titles
declare -a solution_files

while IFS= read -r line || [[ -n "$line" ]]; do
    [[ -z "${line// }" ]] && continue
    title="$(printf '%s' "$line" | sed -E 's/^[0-9]+[[:space:]]*-[[:space:]]*//;s/[[:space:]]*$//')"
    solution_path="${SOLUTIONS_DIR%/}/${title}.cpp"
    if [[ -f "$solution_path" ]]; then
        titles+=("$title")
        solution_files+=("$solution_path")
    fi
done < "$TMPDIR"/_temp_list.txt

# --- Build one big HTML ---
BIG_HTML="$TMPDIR/solutions.html"
cat > "$BIG_HTML" <<HTML
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>$MAIN_TITLE — CSES Solutions</title>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/styles/github.min.css">
<style>
body { font-family: sans-serif; max-width: 900px; margin: 2rem auto; font-size: 10px; }
h1 { text-align: center; font-size: 1.6rem; margin-bottom: 2rem; }
h2 { margin-top: 2rem; font-size: 1.2rem; border-bottom: 1px solid #ccc; padding-bottom: 0.3rem; }
pre { border: 1px solid #ddd; border-radius: 6px; margin-top: 1rem; }
code.hljs { padding: 1em; }
.separator { margin: 3rem 0; border-top: 2px dashed #aaa; }
</style>
</head>
<body>
<h1>$MAIN_TITLE</h1>
HTML

for i in "${!titles[@]}"; do
    title="${titles[i]}"
    solution_file="${solution_files[i]}"
    echo "<h2>${title}</h2>" >> "$BIG_HTML"
    escaped_code=$(sed 's/&/\&amp;/g; s/</\</g; s/>/\>/g' "$solution_file")
    echo "<pre><code class=\"language-cpp\">${escaped_code}</code></pre>" >> "$BIG_HTML"
    echo "<div class=\"separator\"></div>" >> "$BIG_HTML"
done

cat >> "$BIG_HTML" <<'HTML'
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"></script>
<script>hljs.highlightAll();</script>
</body></html>
HTML

# --- Print one single PDF ---
echo "Generating final PDF..."
"$BROWSER_BIN" --headless --disable-gpu --no-sandbox \
    --print-to-pdf="$OUT_PDF" \
    --virtual-time-budget=5000 \
    "file://$BIG_HTML"

echo "✅ Success! Final PDF created at: $OUT_PDF"
