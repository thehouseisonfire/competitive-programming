#include <algorithm>
#include <cmath>
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

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

vector<int> depth;

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;

  for (int i = 1; i <= l; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];

  for (int u : adj[v]) {
    if (u == p)
      continue;

    depth[u] = depth[v] + 1;
    dfs(u, v);
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

void preprocess(int root) {
  tin.resize(n);
  tout.resize(n);
  depth.assign(n, 0);

  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vector<int>(l + 1));
  dfs(root, root);
}

int dist(int u, int v) {
  int w = lca(u, v);
  return depth[u] + depth[v] - 2 * depth[w];
}

void solve() {
  ll q;
  cin >> n >> q;

  adj.assign(n, {});

  for (ll i = 1; i < n; i++) {
    ll a;
    cin >> a;
    a--;

    adj[a].push_back(i);
    adj[i].push_back(a);
  }

  preprocess(0);

  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;

    int ab = dist(a, b);
    int ac = dist(a, c);
    int bc = dist(b, c);

    int ans = max({
        (ac + bc - ab) / 2 + 1,
        (ab + bc - ac) / 2 + 1,
        (ab + ac - bc) / 2 + 1,
    });

    cout << ans << endl;
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
