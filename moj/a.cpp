#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <tuple>
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

vector<tuple<int, int, int>> v;

void solve() {
  ll n;
  cin >> n;
  v.resize(n);
  for (ll i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = {x, y, i};
  }

  sort(v.begin(), v.end());

  auto [winning_count, _, __] = v[n - 1];

  // cout << i << endl;

  for (int i = 0; i < n; i++) {
    auto [curr, res, curr_ind] = v[i];
    if (curr == winning_count) {
      cout << curr_ind + 1 << endl;
      return;
    }
  }

  // cin >> v;
  // cout << v << endl;
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
