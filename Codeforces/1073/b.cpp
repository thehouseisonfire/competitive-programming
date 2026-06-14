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

// Idea: Sorting seems to have some intuitively very nice properties for
// checking this. Basically it puts equal numbers the closest together (you
// don't want equal numbers in the different sides of the split, since it could
// push the MEX of both up if they have a sequence starting from zero)
//
// 0 1 2 | 0 1 2 -> BAD sequence, very evil.
// 0 0 1 | 1 2 2 -> GODD sequence, MEX grows large in one side and stays at 0 or
// 1 in the other

void solve() {
  ll n;
  cin >> n;
  vll v(n);
  cin >> v;
  sort(all(v));
  ll mex_p = v[0] == 0, mex_s = 0, zero_bound = -1;
  for (ll i = 1; i < n; i++) {
    mex_s += mex_s == v[i];
    if (v[i] != 0) {
      zero_bound = i - 1;
      break;
    }
  }
  if (mex_p == mex_s) {
    cout << "NO" << endl;
    return;
  }
  bool flag = 1;
  for (ll i = 1; i < n; i++) {
    mex_p += v[i - 1] + 1 == v[i];
    if (zero_bound == i)
      mex_s = 0;
    if (mex_s == mex_p) {
      flag = 0;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
