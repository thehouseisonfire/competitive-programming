#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
  vector<int> parent;
  vector<int> rank;

public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return;
    if (rank[rootX] < rank[rootY])
      parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
      parent[rootY] = rootX;
    else
      parent[rootY] = rootX, rank[rootX]++;
  }
};

int countDisjointGraphs(const vector<vector<int>> &adjList) {
  int n = adjList.size();
  UnionFind uf(n);
  for (int i = 0; i < n; ++i)
    for (int j : adjList[i])
      uf.unite(i, j);

  vector<bool> visited(n, false);
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int root = uf.find(i);
    if (!visited[root])
      visited[root] = true, count++;
  }
  return count;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int res = countDisjointGraphs(adj);
  cout << res << endl;
  return 0;
}
