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
  vector<vll> v(n, vll(3));
  cin >> v;
  ll ta = v[0][0], tb = v[0][1], tc = v[0][2];

  for (ll i = 1; i < n; i++) {
    ll a = v[i][0];
    ll b = v[i][1];
    ll c = v[i][2];
    ll xa = ta;
    ll xb = tb;
    ll xc = tc;
    ta = max(xb, xc) + a;
    tb = max(xa, xc) + b;
    tc = max(xa, xb) + c;
  }
  cout << max(max(ta, tb), tc) << endl;
}

void solve2() {
  ll n;
  cin >> n;
  vector<vll> v(n, vll(3));
  cin >> v;
  vector<vll> dp(n, vll(3));

  dp[0][0] = v[3][0];
  dp[1][0] = v[2][0];
  dp[2][0] = v[1][0];

  for (ll i = 1; i < n; i++) {
    dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + v[0][i];
    dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + v[1][i];
    dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + v[2][i];
  }
  cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << endl;
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
