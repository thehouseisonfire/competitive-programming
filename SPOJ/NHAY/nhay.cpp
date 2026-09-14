// https://www.spoj.com/problems/NHAY/

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

const ll p = 31;
const ll m = 1e9 + 9;

int val(char c) { return c - 'a' + 1; }

// finds all occurrences of a pattern of length `k`
// in a given input string
void solve() {
  ll n, k;
  string pat, s;
  while (cin >> k >> pat >> s) {

    n = s.size();
    if (n < k) {
      cout << endl;
      continue;
    }
    ll pat_hash = 0, str_hash = 0;
    for (char &c : pat)
      pat_hash = (pat_hash * p + val(c)) % m;

    for (ll i = 0; i < k && i < n; i++)
      str_hash = (str_hash * p + val(s[i])) % m;

    // power(p,k)
    ll power_k = 1;
    for (ll i = 0; i < k; i++)
      power_k = power_k * p % m;

    if (pat_hash == str_hash)
      cout << 0 << endl;

    if (n == k) {
      cout << endl;
      continue;
    }

    for (ll l = 1, r = k; r < n; l++, r++) {
      str_hash = (str_hash * p + val(s[r])) % m;
      // somamos `m` pois senão o hash pode ficar negativo (por causa
      // do módulo baixar o acumulado)
      // não, não tem jeito de escapar
      str_hash = (str_hash - ((val(s[l - 1]) * power_k) % m) + m) % m;
      if (str_hash == pat_hash) {
        cout << l << endl;
      }
    }
  }
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
