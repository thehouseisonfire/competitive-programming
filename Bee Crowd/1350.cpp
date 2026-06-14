#include <cstring>
#include <iostream>

using namespace std;

#define MAXSIZE 1234

bool p;
int x, y;
int n;
int vis[MAXSIZE];
int next[MAXSIZE];

struct Node {
  int u, w;
  Node *next;
};

Node *adj[MAXSIZE]; // Adjacency list

void push_in(int u, int v, int w) {
  Node *new_node = new Node{v, w, adj[u]};
  adj[u] = new_node;
}

void dfs(int u, int v, int f) {
  if (vis[u] == 1) {
    if (f % 2)
      p = false;
    return;
  }

  vis[u] = 1;
  y += 1 - v;
  x += v;

  for (Node *i = adj[u]; i != nullptr; i = i->next) {
    int k = i->u;
    int w = i->w;

    dfs(k, w != v ? 1 : 0, w + f);
  }
}

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); // Fast input/output

  while (cin >> n, n) {
    memset(adj, 0, sizeof(adj)); // Initialize adjacency list
    memset(next, -1, sizeof(next));
    memset(vis, false, sizeof(vis));

    p = true;

    for (int i = 0; i < n; ++i) {
      string str1, str2, str3;
      int number;

      cin >> str1 >> number >> str2 >> str3;
      next[i] = number - 1; // Store the next node
      push_in(number - 1, i,
              str1[0] == 'f' ? 1 : 0); // Push into adjacency list
    }

    int res = 0;

    for (int i = 0; i < n && p; ++i) {
      if (vis[i])
        continue;

      vis[i] = 2; // Mark as visited

      int u = i;
      while (next[u] != -1 && !vis[next[u]]) {
        u = next[u];
        vis[u] = 2; // Mark as visited
      }

      x = y = 0;    // Reset counts
      dfs(u, 0, 0); // Perform DFS

      res += max(x, y); // Update result
    }

    if (!p)
      cout << "Inconsistent\n"; // Output inconsistency
    else
      cout << res << "\n"; // Output result
  }

  return 0;
}
