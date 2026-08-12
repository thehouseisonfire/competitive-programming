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

struct LCA {
  vector<ll> height, euler, first, segtree;
  ll n;

  LCA(vector<vector<ll>> &adj, ll root = 0) {
    n = adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    dfs(adj, root);
    ll m = euler.size();
    segtree.resize(m * 4);
    build(1, 0, m - 1);
  }

  void dfs(vector<vector<ll>> &adj, ll root) {
    vector<ll> parent(n, -1), it(n, 0);
    vector<ll> st;

    parent[root] = root;
    height[root] = 0;
    first[root] = euler.size();
    euler.push_back(root);
    st.push_back(root);

    while (!st.empty()) {
      ll node = st.back();
      if (it[node] == adj[node].size()) {
        st.pop_back();
        if (!st.empty()) {
          euler.push_back(st.back());
        }
        continue;
      }

      ll to = adj[node][it[node]++];

      if (to == parent[node])
        continue;

      parent[to] = node;
      height[to] = height[node] + 1;
      first[to] = euler.size();
      euler.push_back(to);
      st.push_back(to);
    }
  }

  void build(ll node, ll b, ll e) {
    if (b == e) {
      segtree[node] = euler[b];
    } else {
      ll mid = (b + e) / 2;
      build(node << 1, b, mid);
      build(node << 1 | 1, mid + 1, e);
      ll l = segtree[node << 1], r = segtree[node << 1 | 1];
      segtree[node] = (height[l] < height[r]) ? l : r;
    }
  }

  ll query(ll node, ll b, ll e, ll L, ll R) {
    if (b > R || e < L)
      return -1;
    if (b >= L && e <= R)
      return segtree[node];
    ll mid = (b + e) >> 1;

    ll left = query(node << 1, b, mid, L, R);
    ll right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1)
      return right;
    if (right == -1)
      return left;
    return height[left] < height[right] ? left : right;
  }

  ll lca(ll u, ll v) {
    ll left = first[u], right = first[v];
    if (left > right)
      swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
  }
};

void solve() {
  ll n;
  cin >> n;
  vector<vll> adj(n);
  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  ll q;
  cin >> q;
  auto tree = LCA(adj, 0);
  while (q--) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;

    ll res = tree.lca(b, c);
    ll candidate1 = tree.lca(a, b);
    ll candidate2 = tree.lca(a, c);

    if (tree.height[res] < tree.height[candidate1]) {
      res = candidate1;
    }
    if (tree.height[res] < tree.height[candidate2]) {
      res = candidate2;
    }

    cout << res + 1 << endl;
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
