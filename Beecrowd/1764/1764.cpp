#include <algorithm>
#include <iostream>
#include <vector>

#define u8 unsigned char
#define hd short int
#define hu short unsigned
#define lu unsigned
#define ll long long
#define llu long long unsigned
#define float double
#define double long double
#define pi pair<int, int>
#define pll pair<ll, ll>

#define INF 2147483647
#define HINF INF >> 1
#define MOD 1000000007
#define ASCII_NUMBER_OFFSET '0'
#define ASCII_UPPERCASE_OFFSET 'A'
#define ASCII_LOWERCASE_OFFSET 'a'
// #define ASCII_NUMBER_OFFSET 48
// #define ASCII_UPPERCASE_OFFSET 65
// #define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define PI(x) cout << x.first << " " << x.second << endl
#define DUO(x, y) cout << x << " " << y << endl

#define PRINT_VEC(v)                                                           \
  for (const auto &pos : v) {                                                  \
    cout << pos << " ";                                                        \
  }                                                                            \
  cout << endl;

#define PRINT_DUO_VEC(v)                                                       \
  for (const auto &pos : v) {                                                  \
    cout << pos.first << " " << pos.second << endl;                            \
  }                                                                            \
  cout << endl;

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

struct Edge {
  int u, v, weight;
  bool operator<(const Edge &other) const { return weight < other.weight; }
};

struct DSU {
  vector<int> parent, rank;

  DSU(int n) {
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

  bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
      else if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
      else {
        parent[rootY] = rootX;
        rank[rootX]++;
      }
      return true;
    }
    return false;
  }
};

int kruskal(int m, vector<Edge> &edges) {
  sort(edges.begin(), edges.end());
  DSU dsu(m);
  int mst_weight = 0;
  int edges_used = 0;

  for (const auto &edge : edges) {
    if (dsu.unite(edge.u, edge.v)) {
      mst_weight += edge.weight;
      edges_used++;
      if (edges_used == m - 1)
        break;
    }
  }
  return mst_weight;
}
int main(int argc, char *argv[]) {

  ll m, n;
  while (cin >> m >> n) {
    if (!m && !n)
      break;
    vector<Edge> edges(n);
    for (int i = 0; i < n; i++) {
      cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    cout << kruskal(m, edges) << endl;
  }
  return 0;
}
