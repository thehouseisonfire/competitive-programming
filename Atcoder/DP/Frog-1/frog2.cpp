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
  ll n, k;
  cin >> n >> k;
  vll v(n), dp(n, INF);
  cin >> v;
  dp[0] = 0;
  for (ll i = 0; i < n - 1; i++) {
    for (ll j = 1; j <= k && i + j < n; j++) {
      dp[i + j] = min(dp[i + j], dp[i] + abs(v[i] - v[i + j]));
    }
  }
  cout << dp[n - 1] << endl;
}

void solve2() {
  ll n, k;
  cin >> n >> k;
  vll v(n), dp(n);
  cin >> v;
  dp[0] = 0;
  for (ll i = 1; i < n; i++) {
    ll op_best = INF;
    for (ll j = max(i - k, 0ll); j < i; j++) {
      ll op_curr = dp[j] + abs(v[j] - v[i]);
      op_best = min(op_best, op_curr);
    }
    dp[i] = op_best;
  }
  cout << dp[0] << endl;
}

void solve3() {
  ll n, k;
  cin >> n >> k;
  vll v(n), dp(n);
  cin >> v;
  dp[n - 1] = 0;
  for (ll i = n - 2; i >= 0; i--) {
    ll op_best = INF;
    for (ll j = i + 1; j < n && j <= i + k; j++) {
      ll op_curr = dp[j] + abs(v[j] - v[i]);
      op_best = min(op_best, op_curr);
    }
    dp[i] = op_best;
  }
  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve2();
  }
  return 0;
}
