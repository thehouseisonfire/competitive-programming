import requests
from bs4 import BeautifulSoup

def scrape_cses_from_list():
    # The main problemset page has a better structure
    list_url = "https://cses.fi/problemset/"
    
    try:
        response = requests.get(list_url)
        response.raise_for_status()
        
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Find all task links in the problemset
        task_links = soup.find_all('a', href=lambda x: x and '/task/' in x)
        
        tasks = []
        
        for link in task_links:
            href = link['href']
            task_number = href.split('/')[-1]
            task_name = link.get_text().strip()
            
            if task_name and task_number.isdigit():
                tasks.append((task_number, task_name))
        
        # Sort and print
        tasks.sort(key=lambda x: int(x[0]))
        
        for task_number, task_name in tasks:
            print(f"{task_number} - {task_name}")
            
    except Exception as e:
        print(f"Error: {e}")

# Run the function
scrape_cses_from_list()
