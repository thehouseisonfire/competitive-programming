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
  ll n, w;
  cin >> n >> w;
  vector<pll> v(n);
  cin >> v;
  vll dp(w + 1);
  for (ll i = 0; i < n; i++)
    for (ll j = v[j].first; j <= w; j++)
      dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
  cout << dp[w] << endl;
}

void solve_b() {
  ll n, w;
  cin >> n >> w;
  vector<pll> v(n);
  cin >> v;
  ll sum = 0;
  for (ll i = 0; i < n; i++)
    sum += v[i].second;

  // cout << sum << endl;
  vll dp(sum + 1, INF);
  dp[0] = 0;
  for (ll i = 0; i < n; i++) {

    for (ll j = sum; j >= v[i].second; j--)
      if (dp[j - v[i].second] + v[i].first < dp[j]) {
        dp[j] = dp[j - v[i].second] + v[i].first;
      }

    // for (ll valor = 0; valor <= sum; valor++) {
    //   cout << valor << " ";
    // }
    // cout << endl;

    // for (ll valor = 0; valor <= sum; valor++) {
    //   const auto peso = dp[valor];
    //   cout << peso << " ";
    // }
    // cout << endl;
    // cout << endl;
  }

  for (ll i = sum; i >= 0; i--) {
    if (dp[i] <= w) {
      cout << i << endl;
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve_b();
  }
  return 0;
}
