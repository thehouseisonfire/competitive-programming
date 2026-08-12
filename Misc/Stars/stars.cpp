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

vector<ll> primes_to_n(ll n) {
  vll p;

  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      p.push_back(i);
    }
  }
  if (n != 1)
    p.push_back(n);
  return p;
}

ll phi(ll n) {
  vll p = primes_to_n(n);
  vll filtered;
  for (const auto prime : p)
    if (n % prime == 0)
      filtered.push_back(prime);

  ll prod = n;
  for (const auto prime : filtered) {
    prod -= prod / prime;
  }
  return prod;
}

ll phi2(ll n) {
  vll p = primes_to_n(n);
  ll x = n;
  for (ll i = 0; i < p.size() && p[i] * p[i] <= x; i++) {
    if (x % p[i] == 0) {
      while (x % p[i] == 0)
        x /= p[i];
      n -= n / p[i];
    }
  }
  if (x != 1)
    n -= n / x;
  return n;
}

void solve() {
  ll n;
  while (cin >> n) {
    ll res = phi2(n) / 2;
    cout << res << endl;
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
