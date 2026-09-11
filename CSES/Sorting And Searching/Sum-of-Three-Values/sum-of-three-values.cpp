#include <cmath>
#include <iostream>
#include <unordered_map>
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
  ll n, m;
  cin >> n >> m;
  vll v(n);
  cin >> v;

  for (ll k = 0; k < n; k++) {
    ll target = m - v[k];
    unordered_map<ll, ll> mp;
    mp.reserve(n * 2);
    mp.max_load_factor(0.7);

    for (ll i = 0; i < n; i++) {
      if (i == k)
        continue;

      ll need = target - v[i];
      if (mp.count(need)) {
        cout << k + 1 << " " << i + 1 << " " << mp[need] << "\n";
        return;
      }
      mp[v[i]] = i + 1;
    }
  }
  cout << "IMPOSSIBLE" << endl;
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
