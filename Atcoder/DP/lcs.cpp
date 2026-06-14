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

int solution(int num, const vi &choices, const vi &results);

void solve() {
  ll n, m;
  string s, t;
  cin >> s >> t;
  n = s.size(), m = t.size();
  vector<vll> dp(n + 1, vll(m + 1));
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else if (dp[i][j - 1] > dp[i - 1][j])
        dp[i][j] = dp[i][j - 1];
      else
        dp[i][j] = dp[i - 1][j];

  string res;
  ll i = n, j = m;
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1])
      res += s[i - 1], i--, j--;
    else if (dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }

  reverse(all(res));
  // cout << dp[n][m] << endl;
  cout << res << endl;
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
