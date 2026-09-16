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

vector<ll> dist;

void dijkstra(ll s, vector<vector<pll>> adj, vector<ll> &d) {
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
  ll n, m, c, start;

  while (cin >> n >> m >> c >> start) {
    if (!n && !m && !c && !start)
      break;
    adj.assign(n, {});
    dist.assign(n, INF);
    for (ll i = 0; i < m; i++) {
      ll a, b, w;
      cin >> a >> b >> w;
      if (a >= c && b >= c) {
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
      } else if (a >= c && b < c) {
        adj[a].push_back({b, w});
      } else if (b >= c && a < c) {
        adj[b].push_back({a, w});
      } else if (a < c && b < c) {
        if (a + 1 == b)
          adj[a].push_back({b, w});
        else if (b + 1 == a)
          adj[b].push_back({a, w});
      }
    }
    dijkstra(start, adj, dist);

    cout << dist[c - 1] << endl;
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
