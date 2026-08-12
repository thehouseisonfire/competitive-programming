#include <cmath>
#include <deque>
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

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<vector<pll>> v(n + k);
  for (ll i = 0; i < k; i++) {
    ll l;
    cin >> l;
    ll rep = n + i;
    for (ll j = 0; j < l; j++) {
      ll next;
      cin >> next;
      next--;
      v[rep].push_back({next, 0});
      v[next].push_back({rep, 1});
    }
  }

  vector<ll> d(n + k, INF);
  d[0] = 0;
  deque<ll> q;
  q.push_front(0);
  while (!q.empty()) {
    ll curr = q.front();
    q.pop_front();
    for (auto [u, w] : v[curr]) {
      if (d[curr] + w < d[u]) {
        d[u] = d[curr] + w;
        if (w == 1)
          q.push_back(u);
        else
          q.push_front(u);
      }
    }
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
