#include <cmath>
#include <iomanip>
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

const ll MAXN = 3e3 + 5;

int solution(int num, const vi &choices, const vi &results);

double dp[MAXN][MAXN] = {};

void solve() {
  ll n;
  cin >> n;
  vector<double> v(n);
  cin >> v;

  dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      dp[i][j + 1] += dp[i][j] * (1.0 - v[j]);
      dp[i + 1][j + 1] += dp[i][j] * v[j];
    }
  }

  double sum = 0;
  for (int i = (n + 1) >> 1; i <= n; i++)
    sum += dp[i][n];

  cout << fixed << setprecision(10) << sum << endl;
}

void solve_knapsack() {
  ll n;
  cin >> n;
  vector<double> v(n);
  vector<double> dp(n + 1);
  cin >> v;

  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j >= 0; j--) {
      dp[j] = dp[j] * (1.0 - v[i]) + (j > 0 ? dp[j - 1] * v[i] : 0);
    }
  }

  double sum = 0;
  for (int i = (n + 1) >> 1; i <= n; i++)
    sum += dp[i];

  cout << fixed << setprecision(10) << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve_knapsack();
  }
  return 0;
}
