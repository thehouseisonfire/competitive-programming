#include <cmath>
#include <ios>
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
// const ll INF = 1e9;
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

vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll s, vector<ll> &d) {
  ll n = adj.size();
  d.assign(n, INF);

  d[s] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, s});
  while (!q.empty()) {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : adj[v]) {
      ll to = edge.first;
      ll len = edge.second;

      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        q.push({d[to], to});
      }
    }
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;
  adj.resize(n);
  for (ll i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  vector<ll> d;
  dijkstra(0, d);

  if (d[n - 1] == INF) {
    cout << -1 << endl;
    return;
  }
  cout << d[n - 1] << endl;
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
