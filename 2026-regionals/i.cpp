#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
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

vector<vector<ll>> adj;
vector<pll> rep;
vector<pll> evt;
vector<bool> visited;
vector<bool> willcome;
vector<pair<ll, pll>> timer;

ll dfs(ll v) {
  visited[v] = true;
  ll count = 0;
  for (auto pos : adj[v]) {
    if (visited[pos])
      continue;
    auto res = dfs(pos);
    count += res;
  }
  return count;
}

void solve() {
  ll n, f;
  cin >> n >> f;
  vector<ll> mapa(n);
  vector<ll> repcount(f, -1);

  for (ll i = 0; i < f; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    repcount[i] = b;
    mapa[a] = i;
  }

  adj.resize(f);
  visited.resize(f);
  willcome.resize(f);
  for (ll i = 0; i < n; i++) {
    char a;
    cin >> a;
    if (a == 'D')
      repcount[i] = -1;
    if (a == 'T') {
      ll b;
      cin >> b;
      b--;
      adj[i].push_back(mapa[b]);
    }
    if (a == 'A') {
      ll b, c;
      cin >> b >> c;
      adj[i].push_back(-1);
      // evt.push_back(i, );
      willcome[i] = 1;
      timer.push_back({i, {b, c}});
    }
  }

  for (ll i = 0; i < n; i++) {
    if (!willcome[i])
      continue;
    auto res = dfs(i);
    rep.push_back({i, res});
  }
  assert(rep.size() == timer.size());
  for (ll i = 0; i < rep.size(); i++) {
    evt.push_back({});
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
