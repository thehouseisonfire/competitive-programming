#include <cmath>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<double>;

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

int n, k;
#define max 2000000000

int solution(int qnt, const vector<int> &choices, vector<int> &res) {
  if (qnt < 0)
    return max;
  if (qnt == 0)
    return 0;
  if (res[qnt] != -1)
    return res[qnt];
  int best = max;
  for (const auto &c : choices) {
    if (qnt >= c)
      best = min(best, 1 + solution(qnt - c, choices, res));
  }
  return res[qnt] = best;
}

void solve() {
  cin >> n >> k;
  vector<int> v(n), res(k + 1, -1);
  cin >> v;
  int ans = solution(k, v, res);
  cout << (ans == max ? -1 : ans) << endl;
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
