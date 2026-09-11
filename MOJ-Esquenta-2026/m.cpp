#include <cmath>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v)
    is >> x;
  return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size(); ++i)
    os << (i > 0 ? " " : "") << v[i];
  return os;
}

#define dbg(x) cerr << #x << " = " << (x) << endl
#define all(x) (x).begin(), (x).end()

struct LCA {
  vector<int> height, euler, first;
  // vector<int> segtree;
  vector<pii> segtree;
  vector<bool> visited;
  int n;

  LCA(vector<vector<int>> &adj, vector<int> &v, int root = 0) {
    n = adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);
    dfs(adj, root);
    int m = euler.size();
    segtree.resize(m * 4);
    build(1, 0, m - 1, v);
  }

  void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
      if (!visited[to]) {
        dfs(adj, to, h + 1);
        euler.push_back(node);
      }
    }
  }

  void build(int node, int b, int e, vector<int> &v) {
    if (b == e) {
      segtree[node] = {euler[b], v[b]};
    } else {
      int mid = (b + e) / 2;
      build(node << 1, b, mid, v);
      build(node << 1 | 1, mid + 1, e, v);
      auto l = segtree[node << 1], r = segtree[node << 1 | 1];
      segtree[node] = (height[l.first] < height[r.first]) ? l : r;
    }
  }

  // pii query(int node, int b, int e, int L, int R) {
  //   if (b > R || e < L)
  //     return {-1, -1};
  //   if (b >= L && e <= R)
  //     return segtree[node];
  //   int mid = (b + e) >> 1;
  //
  //   auto left = query(node << 1, b, mid, L, R);
  //   auto right = query(node << 1 | 1, mid + 1, e, L, R);
  //   if (left.first == -1)
  //     return right;
  //   if (right.first == -1)
  //     return left;
  //   return height[left.first] < height[right.first] ? left : right;
  // }
  //
  // pii lca(int u, int v) {
  //   int left = first[u], right = first[v];
  //   if (left > right)
  //     swap(left, right);
  //   return query(1, 0, euler.size() - 1, left, right);
  // }
};

void solve() {
  ll n, q;
  cin >> n >> q;
  vector<int> v(n);
  vector<vector<int>> adj(n);
  cin >> v;
  for (int i = 1; i <= n - 1; i++) {
    int x;
    cin >> x;
    x--;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  auto tree = LCA(adj, v);

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    // auto [lca, ans] = tree.lca(a, b);
    // cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
