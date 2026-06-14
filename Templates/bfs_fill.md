## BFS Grid Flood-Fill Cookbook

The code you shared implements **connected component counting** using BFS flood-fill. Here's a distilled template that works across common grid traversal problems:

### Core Template

```cpp
// Direction vectors (4-directional)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
// For 8-directional: {-1,-1,-1,0,0,1,1,1}, {-1,0,1,-1,1,-1,0,1}

template<typename Grid, typename Condition, typename Action>
void bfs_fill(Grid& grid, int sx, int sy, int n, int m, 
              Condition can_visit, Action on_visit) {
    queue<pii> q;
    q.push({sx, sy});
    on_visit(sx, sy);
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                can_visit(nx, ny)) {
                q.push({nx, ny});
                on_visit(nx, ny);
            }
        }
    }
}
```

### Common Patterns

**Pattern 1: Count Connected Components** (your code)
```cpp
int count_components(vector<vc>& grid, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                bfs_fill(grid, i, j, n, m,
                    [&](int x, int y) { return grid[x][y] == '.'; },
                    [&](int x, int y) { grid[x][y] = '#'; });
                count++;
            }
        }
    }
    return count;
}
```

**Pattern 2: Component Sizes**
```cpp
vector<int> get_component_sizes(vector<vc>& grid, int n, int m) {
    vector<int> sizes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int size = 0;
                bfs_fill(grid, i, j, n, m,
                    [&](int x, int y) { return grid[x][y] == '.'; },
                    [&](int x, int y) { grid[x][y] = '#'; size++; });
                sizes.push_back(size);
            }
        }
    }
    return sizes;
}
```

**Pattern 3: Shortest Path with BFS**
```cpp
int shortest_path(vector<vc>& grid, int sx, int sy, int ex, int ey, int n, int m) {
    vector<vi> dist(n, vi(m, -1));
    queue<pii> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == ex && y == ey) return dist[x][y];
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; // unreachable
}
```

### Performance Notes

- **Time**: \(O(n \times m)\) to visit all cells once
- **Space**: \(O(n \times m)\) worst case queue size (entire grid in queue)
- **Stack safety**: BFS avoids recursion depth issues that DFS can hit on 10⁶+ grids
