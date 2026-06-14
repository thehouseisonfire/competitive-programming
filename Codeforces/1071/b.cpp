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
  vll v(n);
  cin >> v;
  ll sum = 0, sum2 = 0, sum3 = 0;
  ll biggest_diff = -INF;
  ll biggest_diff_idx = -1;
  for (int i = 0, j = 1, k = 2; k < v.size(); i++, j++, k++) {
    ll x = abs(v[j] - v[i]);
    ll y = abs(v[k] - v[j]);
    ll a = abs(v[k] - v[i]);
    ll diff = abs((x + y) - a);
    if (diff > biggest_diff) {
      biggest_diff = diff;
      biggest_diff_idx = j;
    }
  }

  for (int i = 1; i < v.size(); i++) {
    if (i == biggest_diff_idx)
      continue;
    ll x;
    if (i == biggest_diff_idx + 1) {
      x = abs(v[i] - v[i - 2]);
    } else
      x = abs(v[i] - v[i - 1]);
    sum += x;
  }

  for (int i = 2; i < v.size(); i++) {
    ll x = abs(v[i] - v[i - 1]);
    sum2 += x;
  }
  for (int i = 1; i < v.size() - 1; i++) {
    ll x = abs(v[i] - v[i - 1]);
    sum3 += x;
  }

  cout << min(min(sum, sum2), sum3) << endl;
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
