import os
import fitz

def merge_pdfs_fitz():
    if not os.path.exists('order.txt'):
        print("Error: 'order.txt' file not found!")
        return
    
    try:
        with open('order.txt', 'r') as f:
            pdf_files = [line.strip() for line in f.readlines() if line.strip()]
    except Exception as e:
        print(f"Error reading order.txt: {e}")
        return
    
    existing_files = [f for f in pdf_files if os.path.exists(f)]
    missing_files = [f for f in pdf_files if not os.path.exists(f)]
    
    if missing_files:
        print(f"Warning: Missing files: {missing_files}")
    
    if not existing_files:
        print("No PDF files to merge!")
        return
    
    # Create output PDF
    output_doc = fitz.open()
    
    try:
        for pdf_file in existing_files:
            doc = fitz.open(pdf_file)
            output_doc.insert_pdf(doc)
            doc.close()
            print(f"Added: {pdf_file}")
        
        output_filename = "merged_output.pdf"
        output_doc.save(output_filename)
        print(f"\nMerged {len(existing_files)} files into {output_filename}")
        
    except Exception as e:
        print(f"Error: {e}")
    
    finally:
        output_doc.close()

if __name__ == "__main__":
    merge_pdfs_fitz()
