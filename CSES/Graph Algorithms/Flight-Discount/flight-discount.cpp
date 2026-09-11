#include <cmath>
#include <iostream>
#include <queue>
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

vector<vector<pll>> adj;
vector<vector<pll>> backwards_adj;

vector<ll> ds, df;
vector<ll> ps, pf;

void dijkstra(ll s, vector<vector<pll>> adj, vector<ll> &d, vector<ll> &p) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  d[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [p, v] = pq.top();
    pq.pop();

    if (p != d[v])
      continue;

    for (const auto [to, w] : adj[v]) {
      if (d[v] + w < d[to]) {
        d[to] = d[v] + w;
        pq.push({d[to], to});
      }
    }
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;
  adj.assign(n, {});
  backwards_adj.assign(n, {});

  ds.assign(n, INF);
  df.assign(n, INF);
  ps.assign(n, -1);
  pf.assign(n, -1);
  vector<tuple<ll, ll, ll>> edges;
  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({b, c});
    backwards_adj[b].push_back({a, c});
    edges.push_back({a, b, c});
  }
  dijkstra(0, adj, ds, ps);
  dijkstra(n - 1, backwards_adj, df, pf);

  ll best = INF;
  for (auto [u, v, c] : edges) {
    best = min(best, ds[u] + c / 2 + df[v]);
  }
  cout << best << endl;
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
