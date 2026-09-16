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

int solution(int num, const vi &choices, const vi &results);

void solve() {
  ll n;
  cin >> n;
  vll tries(n), errors(n);
  cin >> tries >> errors;
  sort(all(errors));
  bool identical = true;
  ll min_try = INF, max_try = -1, max_err = errors[n - 1];
  for (ll i = 1; i < n; i++) {
    if (tries[i - 1] != tries[i]) {
      identical = false;
    }
  }
  for (ll i = 0; i < n; i++) {
    min_try = min(min_try, tries[i]);
    max_try = max(max_try, tries[i]);
  }

  if (identical) {
    if (tries[0] - errors[0] > 0)
      cout << tries[0] - errors[0] << endl;
    if (tries[0] + errors[0] < (ll)1e9 + 1)
      cout << tries[0] + errors[0] << endl;
    return;
  }
  ll candidate1 = max_try - max_err, candidate2 = min_try + max_err;

  bool flag1 = 1, flag2 = 1;

  if (candidate1 > 0 && candidate1 < (ll)1e9 + 1) {
    vector<ll> results(n);
    for (ll i = 0; i < n; i++)
      results[i] = abs(tries[i] - candidate1);
    sort(all(results));
    for (ll i = 0; i < n; i++) {
      if (results[i] != errors[i]) {
        flag1 = false;
        break;
      }
    }
  } else
    flag1 = false;
  if (candidate2 > 0 && candidate2 < (ll)1e9 + 1) {
    vector<ll> results(n);
    for (ll i = 0; i < n; i++)
      results[i] = abs(tries[i] - candidate2);
    sort(all(results));
    for (ll i = 0; i < n; i++) {
      if (results[i] != errors[i]) {
        flag2 = false;
        break;
      }
    }
  } else
    flag2 = false;
  if (candidate1 == candidate2 && flag1) {
    cout << candidate1 << endl;
    return;
  }
  if (flag1)
    cout << candidate1 << endl;
  if (flag2)
    cout << candidate2 << endl;
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
