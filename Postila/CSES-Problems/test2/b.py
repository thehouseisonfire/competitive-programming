# Read numbers.txt into a dictionary: problem_name -> number
number_map = {}
with open("numbers.txt", "r", encoding="utf-8") as f:
    for line in f:
        if " - " in line:
            num, name = line.strip().split(" - ", 1)
            number_map[name] = num

# Read class.txt and build output with numbers
output_lines = []
current_section = ""

with open("class.txt", "r", encoding="utf-8") as f:
    for line in f:
        stripped = line.strip()
        if not stripped:
            continue  # Skip empty lines

        # Check if it's a section header (no numbers, not a ratio line)
        if " / " not in stripped and stripped not in number_map:
            current_section = stripped
            output_lines.append(f"\n{current_section}\n")
        else:
            # It's a problem name if it's not a "X / Y" line
            if " / " not in stripped:
                problem_name = stripped
                if problem_name in number_map:
                    number = number_map[problem_name]
                    output_lines.append(f"{number} - {problem_name}\n")

# Write to output.txt
with open("output.txt", "w", encoding="utf-8") as f:
    # Join lines and remove leading newline
    f.write("".join(output_lines).lstrip())
