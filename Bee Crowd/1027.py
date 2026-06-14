def max_critical_points(points):
    # Sort points based on x-coordinate
    points.sort()
    
    # Initialize variables to keep track of selected points
    selected_points = []
    
    for x, y in points:
        if len(selected_points) == 0 or (y != selected_points[-1][1] and abs(y - selected_points[-1][1]) == 2):
            selected_points.append((x, y))
    
    return len(selected_points)

# Read input and process each test case
import sys

input_data = sys.stdin.read().strip().splitlines()
index = 0

while index < len(input_data):
    N = int(input_data[index])
    index += 1
    
    points = []
    for _ in range(N):
        x, y = map(int, input_data[index].split())
        points.append((x, y))
        index += 1
    
    result = max_critical_points(points)
    print(result)
