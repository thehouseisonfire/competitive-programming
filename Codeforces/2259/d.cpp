#include <cmath>
#include <functional>
#include <iostream>
#include <set>
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
  ll n;
  cin >> n;
  vll v(n);
  cin >> v;
  vector<set<ll>> sets(3);
  vector<ll> mexs(3, -1);
  string res;
  ll lesser = 0;
  for (const auto &pos : v) {
    sets[lesser].insert(pos);
    res.push_back(lesser == 0 ? 'A' : (lesser == 1 ? 'B' : 'C'));
    if (pos == 0 && mexs[lesser] == -1) {
      mexs[lesser] = 1;
      if (mexs[0] < mexs[1] && mexs[0] < mexs[2])
        lesser = 0;
      else if (mexs[1] < mexs[0] && mexs[1] < mexs[2])
        lesser = 1;
      else if (mexs[2] < mexs[0] && mexs[2] < mexs[1])
        lesser = 2;
    } else if (pos == mexs[lesser]) {
      mexs[lesser]++;
      while (sets[lesser].count(mexs[lesser]))
        mexs[lesser]++;
      if (mexs[0] < mexs[1] && mexs[0] < mexs[2])
        lesser = 0;
      else if (mexs[1] < mexs[0] && mexs[1] < mexs[2])
        lesser = 1;
      else if (mexs[2] < mexs[0] && mexs[2] < mexs[1])
        lesser = 2;
    }
    cout << mexs << endl;
    dbg(lesser);
  }
  ll beat = 2 * max(mexs[0], max(mexs[1], mexs[2]));
  ll sum = mexs[0] + mexs[1] + mexs[2];
  dbg(beat);
  dbg(sum);
  if (beat > sum) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  cout << res << endl;
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
