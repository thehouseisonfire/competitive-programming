#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vi = vector<int>;

struct DSU {
  vi parent, size;

  DSU(int n) : parent(n), size(n, 1) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find(parent[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
      return false;

    if (size[a] < size[b])
      swap(a, b);

    parent[b] = a;
    size[a] += size[b];
    return true;
  }
};

struct Edge {
  int u, v;
  ll weight;

  bool operator<(const Edge &other) const { return weight < other.weight; }
};

ll solution(int n, vector<Edge> &edges) {
  sort(edges.begin(), edges.end());

  DSU dsu(n);
  ll cost = 0;
  int edge_count = 0;

  for (const auto &[u, v, weight] : edges) {
    if (!dsu.unite(u, v))
      continue;

    cost += weight;
    edge_count++;

    if (edge_count == n - 1)
      break;
  }

  return edge_count == n - 1 ? cost : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);
  for (auto &[u, v, weight] : edges) {
    cin >> u >> v >> weight;
    u--, v--;
  }

  ll result = solution(n, edges);

  if (result == -1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << result << endl;

  return 0;
}
