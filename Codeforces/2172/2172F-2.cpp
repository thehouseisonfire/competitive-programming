#include <cmath>
#include <iostream>
#include <numeric>
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
  int n;
  cin >> n;
  vi v(n);
  cin >> v;

  vector<ll> pre(n);
  pre[0] = v[0];
  for (int i = 1; i < n; i++) {
    pre[i] = gcd(pre[i - 1], v[i]);
  }

  vector<ll> suf(n);
  suf[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = gcd(suf[i + 1], v[i]);
  }

  ll total_cost = 0;
  for (int i = 1; i < n; i++) {
    total_cost += min(pre[i], suf[i]);
  }

  cout << total_cost << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
