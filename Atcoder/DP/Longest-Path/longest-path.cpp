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

int solution(int num, const vi &choices, const vi &results);

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vll> v(n);
  vll sources(n, 1);
  vll dist(n);
  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    sources[b] = 0;
  }
  vector<ll> leafs;
  for (ll i = 0; i < n; i++) {
    if (!v[i].size())
      leafs.push_back(i);
  }
  for (ll source = 0; source < n; source++) {
    if (!sources[source])
      continue;
    queue<pll> q;
    q.push({source, 0});
    while (!q.empty()) {
      const auto pos = q.front();
      q.pop();
      if (dist[pos.first] < pos.second)
        break;
      dist[pos.first] = pos.second;
      for (ll k = 0; k < v[pos.first].size(); k++)
        q.push({v[pos.first][k], pos.second + 1});
    }
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
