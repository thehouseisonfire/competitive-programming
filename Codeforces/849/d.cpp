#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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
  string v;
  cin >> v;
  ll sum_total = 0, sum_left = 0, sum_right = 0;
  map<char, ll> map_left, map_right;
  for (const auto &pos : v) {
    map_right[pos]++;
  }
  for (const auto &[ch, num] : map_right) {
    sum_right += min(num, 1ll);
  }
  sum_total = sum_right;
  for (const auto &pos : v) {
    map_left[pos]++;
    map_right[pos]--;
    const ll wl = map_left[pos];
    const ll wr = map_right[pos];
    if (wl <= 1)
      sum_left++;
    if (wr < 1)
      sum_right--;
    sum_total = max(sum_total, sum_left + sum_right);
  }
  cout << sum_total << endl;
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
