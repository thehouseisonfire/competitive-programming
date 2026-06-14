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
  ll n;
  cin >> n;
  vll v(n), dp(n, INF);
  dp[0] = 0;
  cin >> v;
  ll sum = 0;
  for (ll i = 0; i < n - 1; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(v[i] - v[i + 1]));
    if (i < n - 2)
      dp[i + 2] = min(dp[i + 2], dp[i] + abs(v[i] - v[i + 2]));
  }
  cout << dp[n - 1] << endl;
}

void solve2() {
  ll n;
  cin >> n;
  vll v(n), dp(n);
  cin >> v;
  dp[n - 1] = 0;
  for (ll i = n - 2; i >= 0; i--) {
    ll op = dp[i + 1] + abs(v[i] - v[i + 1]);
    ll op2 = i != n - 2 ? dp[i + 2] + abs(v[i] - v[i + 2]) : INF;
    dp[i] = min(op, op2);
  }
  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve2();
  }
  return 0;
}
