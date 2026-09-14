def shortest_cycle(graph):
    # Initialize an empty stack and a visited set
    stack = []
    visited = set()
    min_cycle_length = float('inf')

    # Start DFS traversal from an arbitrary node
    node = 0  # Choose an arbitrary node as the starting point
    stack.append(node)
    visited.add(node)

    while stack:
        node = stack.pop()
        for neighbor in graph[node]:
            if neighbor not in visited:
                stack.append(neighbor)
                visited.add(neighbor)
            elif neighbor != node:
                cycle_length = len(stack) - visited.index(neighbor)
                min_cycle_length = min(min_cycle_length, cycle_length)

    return min_cycle_length if min_cycle_length != float('inf') else -1
