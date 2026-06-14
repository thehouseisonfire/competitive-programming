# 🌲 DFS Patterns Guide: Problems, Intuition, and Solutions

Here's a beautifully formatted version of your DFS patterns guide with improved visual hierarchy, clearer sections, and better readability:

***

## 📋 Table of Contents

1. [Pattern 1: Topological Sort / Post-Order Traversal](#pattern-1)
2. [Pattern 2: Parent Tracking / Path Queries](#pattern-2)
3. [Pattern 3: Depth / Level / Time Tracking](#pattern-3)
4. [Complete Tree DFS Template](#complete-template)
5. [Pattern Selection Guide](#pattern-selection)

***

## 🔄 Pattern 1: Topological Sort / Post-Order Traversal

### The Problem

You have tasks with dependencies: "Task B requires Task A to be done first." How do you order all tasks so dependencies are respected? More formally: given a directed acyclic graph (DAG), find an ordering where every edge u→v has u before v.

### Why DFS?

DFS naturally gives you **post-order traversal**: a node is processed after all its descendants. This is exactly what you need—a task should only be "finished" after all its dependencies are finished.

> 💡 **Intuition**: Think of it like cleaning your room—you can't say "room is clean" until you've finished cleaning every corner. DFS visits every corner (child) first, then marks the room (parent) as complete.

### How It Works

```text
Graph: A → B → D
       A → C → D
       
DFS from A:
1. Visit A, explore neighbors...
2. Go to B, explore neighbors...
3. Go to D (from B), no neighbors → finish D [push D]
4. Back to B, done with neighbors → finish B [push B]
5. Go to C, explore neighbors...
6. Go to D (already visited), skip
7. Back to C, done with neighbors → finish C [push C]
8. Back to A, done with neighbors → finish A [push A]

Result (reversed): [D, B, C, A] or [D, C, B, A]
Both valid! D before B and C, B/C before A.
```

**🔑 Key insight**: push nodes to a stack during backtracking (when leaving the node). This ensures children are pushed before parents.

### 💻 Template: Recursive (cleanest)

```cpp
vector<int> topo_order;
vector<bool> visited;

void dfs_topo(vector<vi>& adj, int u) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_topo(adj, v);
        }
    }
    
    // Post-order: add after processing all children
    topo_order.push_back(u);
}

vector<int> topological_sort(vector<vi>& adj, int n) {
    visited.assign(n, false);
    topo_order.clear();
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_topo(adj, i);
        }
    }
    
    reverse(all(topo_order));  // Reverse to get correct order
    return topo_order;
}
```

### 💻 Template: Iterative (with state tracking)

```cpp
vector<int> topological_sort_iterative(vector<vi>& adj, int n) {
    vector<int> topo_order;
    vector<int> state(n, 0);  // 0=white, 1=gray, 2=black
    
    for (int start = 0; start < n; start++) {
        if (state[start] != 0) continue;
        
        stack<int> st;
        st.push(start);
        
        while (!st.empty()) {
            int u = st.top();
            
            if (state[u] == 2) {  // Already done (black)
                st.pop();
                continue;
            }
            
            if (state[u] == 0) {  // First visit (white→gray)
                state[u] = 1;
                // Push all unvisited neighbors
                for (int v : adj[u]) {
                    if (state[v] == 0) {
                        st.push(v);
                    } else if (state[v] == 1) {
                        // Cycle detected! (back edge)
                        return {};  // No valid topological sort
                    }
                }
            } else {  // state[u] == 1, returning from children (gray→black)
                state[u] = 2;
                topo_order.push_back(u);  // Post-order
                st.pop();
            }
        }
    }
    
    reverse(all(topo_order));
    return topo_order;
}
```

***

## 🌳 Pattern 2: Parent Tracking / Path Queries

### The Problem

In a tree, you need to:
- Find the path from any node to the root
- Compute Lowest Common Ancestor (LCA) of two nodes
- Answer "is node X an ancestor of node Y?"
- Navigate up the tree (child→parent direction)

### Why DFS?

DFS maintains the call stack which naturally represents the path from root to current node. As you recurse deeper, you're building the path; as you backtrack, you're unwinding it. By storing each node's parent during traversal, you can later reconstruct any path.

### How It Works

```text
Tree:       A
           / \
          B   C
         / \
        D   E

DFS from A:
- Visit A (parent=-1, depth=0)
  - Visit B (parent=A, depth=1)
    - Visit D (parent=B, depth=2)
    - Visit E (parent=B, depth=2)
  - Visit C (parent=A, depth=1)

Path from D to root: D→B→A (follow parent pointers)
LCA(D, E): Walk up from both until they meet → B
```

### 💻 Template: Parent Tracking & Tree Queries

```cpp
vector<int> parent, depth;
vector<bool> visited;

void dfs_tree(vector<vi>& adj, int u, int par = -1, int d = 0) {
    visited[u] = true;
    parent[u] = par;
    depth[u] = d;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_tree(adj, v, u, d + 1);  // Pass u as parent
        }
    }
}

void build_tree(vector<vi>& adj, int root, int n) {
    parent.assign(n, -1);
    depth.assign(n, 0);
    visited.assign(n, false);
    dfs_tree(adj, root);
}

// Get path from node u to root
vector<int> get_path_to_root(int u) {
    vector<int> path;
    while (u != -1) {
        path.push_back(u);
        u = parent[u];
    }
    reverse(all(path));  // Optional: root first
    return path;
}

// Naive LCA: walk both nodes up to same depth, then walk together
int lca(int u, int v) {
    // Bring to same depth
    while (depth[u] > depth[v]) u = parent[u];
    while (depth[v] > depth[u]) v = parent[v];
    
    // Walk up together until they meet
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

// Distance between two nodes
int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}
```

### 💻 Iterative Version

```cpp
struct DFSState {
    int node, par, depth;
};

void build_tree_iterative(vector<vi>& adj, int root, int n) {
    parent.assign(n, -1);
    depth.assign(n, 0);
    vector<bool> visited(n, false);
    
    stack<DFSState> st;
    st.push({root, -1, 0});
    
    while (!st.empty()) {
        auto [u, par, d] = st.top();
        st.pop();
        
        if (visited[u]) continue;
        
        visited[u] = true;
        parent[u] = par;
        depth[u] = d;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                st.push({v, u, d + 1});
            }
        }
    }
}
```

***

## ⏱️ Pattern 3: Depth / Level / Time Tracking

### The Problem

You need to know when DFS visits each node:
- **Entry time (pre-order)**: when DFS first arrives at a node
- **Exit time (post-order)**: when DFS finishes exploring that subtree
- **Subtree queries**: "Is node X in the subtree of node Y?"
- **Subtree sizes**: "How many nodes are under this node?"

### Why DFS with Timestamps?

A node's subtree is contiguous in DFS order. If you assign each node an entry time and exit time, you can check "is X in subtree of Y?" in O(1): just check if `time_in[Y] ≤ time_in[X] ≤ time_out[Y]`.

> 💡 **Intuition**: This works because DFS fully explores each subtree before moving to the next, creating a nested interval property.

### How It Works

```text
Tree:       A
           / \
          B   C
         / \
        D   E

DFS with time tracking:
time=0: Enter A (time_in[A]=0)
time=1:   Enter B (time_in[B]=1)
time=2:     Enter D (time_in[D]=2)
time=3:     Exit D (time_out[D]=3)
time=4:     Enter E (time_in[E]=4)
time=5:     Exit E (time_out[E]=5)
time=6:   Exit B (time_out[B]=6)
time=7:   Enter C (time_in[C]=7)
time=8:   Exit C (time_out[C]=8)
time=9: Exit A (time_out[A]=9)

Is E in subtree of B?
  time_in[B]=1 ≤ time_in[E]=4 ≤ time_out[B]=6 ✓ Yes!
Is C in subtree of B?
  time_in[B]=1 ≤ time_in[C]=7 ≤ time_out[B]=6 ✗ No!
```

### 💻 Template: Timestamps & Subtree Queries

```cpp
vector<int> time_in, time_out, depth, subtree_size;
int timer = 0;

int dfs_time(vector<vi>& adj, int u, int par = -1, int d = 0) {
    time_in[u] = timer++;
    depth[u] = d;
    
    int size = 1;  // Count self
    for (int v : adj[u]) {
        if (v != par) {
            size += dfs_time(adj, v, u, d + 1);
        }
    }
    
    subtree_size[u] = size;
    time_out[u] = timer++;
    return size;
}

void initialize_tree(vector<vi>& adj, int root, int n) {
    time_in.assign(n, 0);
    time_out.assign(n, 0);
    depth.assign(n, 0);
    subtree_size.assign(n, 0);
    timer = 0;
    dfs_time(adj, root);
}

// Check if v is in subtree of u
bool is_ancestor(int u, int v) {
    return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
}

// All nodes in subtree have time_in values in range [time_in[u], time_out[u]]
// Useful for segment tree / Fenwick tree range queries
pair<int, int> subtree_range(int u) {
    return {time_in[u], time_out[u]};
}
```

### 💻 Grid Version: Distance from Source

```cpp
vector<vi> dist;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs_grid_dist(vector<vc>& grid, int x, int y, int n, int m, int d = 0) {
    if (x < 0 || x >= n || y < 0 || y >= m || 
        grid[x][y] == '#' || dist[x][y] != -1) {
        return;
    }
    
    dist[x][y] = d;
    
    for (int i = 0; i < 4; i++) {
        dfs_grid_dist(grid, x + dx[i], y + dy[i], n, m, d + 1);
    }
}

// Initialize and run
void compute_distances(vector<vc>& grid, int sx, int sy, int n, int m) {
    dist.assign(n, vi(m, -1));
    dfs_grid_dist(grid, sx, sy, n, m);
}
```

***

## 🎯 Complete Tree DFS Template (All Features)

```cpp
struct TreeDFS {
    int n, timer;
    vector<vi> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> time_in, time_out;
    
    TreeDFS(int n) : n(n), timer(0), adj(n), parent(n), depth(n), 
                      subtree_size(n), time_in(n), time_out(n) {}
    
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int dfs(int u, int par = -1, int d = 0) {
        parent[u] = par;
        depth[u] = d;
        time_in[u] = timer++;
        
        int size = 1;
        for (int v : adj[u]) {
            if (v != par) {
                size += dfs(v, u, d + 1);
            }
        }
        
        subtree_size[u] = size;
        time_out[u] = timer++;
        return size;
    }
    
    void build(int root = 0) {
        timer = 0;
        dfs(root);
    }
    
    // Query operations
    bool is_ancestor(int u, int v) {
        return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
    }
    
    int lca(int u, int v) {
        while (depth[u] > depth[v]) u = parent[u];
        while (depth[v] > depth[u]) v = parent[v];
        while (u != v) { u = parent[u]; v = parent[v]; }
        return u;
    }
    
    int distance(int u, int v) {
        int l = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[l];
    }
    
    vector<int> path(int u, int v) {
        int l = lca(u, v);
        vector<int> path1, path2;
        
        // u to lca
        int x = u;
        while (x != l) {
            path1.push_back(x);
            x = parent[x];
        }
        
        // v to lca
        x = v;
        while (x != l) {
            path2.push_back(x);
            x = parent[x];
        }
        
        path1.push_back(l);
        reverse(all(path2));
        path1.insert(path1.end(), all(path2));
        return path1;
    }
};
```

***

## 🗺️ When to Use Each Pattern

| Pattern | Use When | Examples |
|---------|----------|----------|
| 🔄 **Topological Sort** | Need ordering with dependencies | Task scheduling, build systems, course prerequisites |
| 🌳 **Parent Tracking** | Need paths or LCA in trees | File paths, tree navigation, finding common ancestors |
| ⏱️ **Time Stamps** | Need subtree queries or flat representation | Range queries on trees, ancestor checks in O(1) |

All three leverage DFS's fundamental property: it explores depth-first and backtracks naturally, making it perfect for dependency chains, path tracking, and nested structures.
