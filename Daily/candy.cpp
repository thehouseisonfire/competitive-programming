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

void solve() {
  ll n, m;

  while (cin >> n >> m) {
    if (!n || !m)
      continue;

    vll v(n);

    for (ll i = 0; i < n; i++) {
      vll dp(m);
      cin >> dp;

      if (m > 1)
        dp[1] = max(dp[0], dp[1]);

      for (ll j = 2; j < m; j++)
        dp[j] = max(dp[j - 1], dp[j] + dp[j - 2]);

      v[i] = dp[m - 1];
    }

    if (n > 1)
      v[1] = max(v[0], v[1]);

    for (ll i = 2; i < n; i++)
      v[i] = max(v[i - 1], v[i] + v[i - 2]);

    cout << v[n - 1] << endl;
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
