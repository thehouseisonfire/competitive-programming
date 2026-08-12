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
  n--;
  vector<ll> v(6);
  v[0] = 1;
  v[1] = 2;
  v[2] = 4;
  v[3] = 8;
  v[4] = 16;
  v[5] = 32;

  if (n <= 5) {
    cout << v[n] << endl;
    return;
  }

  ll curr = 5;
  while (curr != n) {
    curr++;
    v[curr % 6] = (v[curr % 6] % MOD + v[(curr - 1) % 6] % MOD +
                   v[(curr - 2) % 6] % MOD + v[(curr - 3) % 6] % MOD +
                   v[(curr - 4) % 6] % MOD + v[(curr - 5) % 6] % MOD) %
                  MOD;
    // dbg(curr % 6);
  }
  cout << v[n % 6] % MOD << endl;
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
