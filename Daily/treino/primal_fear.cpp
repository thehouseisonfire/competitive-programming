#include <array>
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

ll num = 0;
ll evil_num = 0;

vector<ll> is_prime((ll)1e6 + 10, 0);
vector<ll> primes((ll)1e3 + 10);

const void sieve(ll n) {

  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }

  for (ll i = 1; i < n; i++) {
    if (is_prime[i]) {
      dbg(i);
      primes[num] = i, num++;
    }
  }
}

bool has_zero(ll n) {
  while (n) {
    ll digit = n % 10;
    if (!digit)
      return true;
    n /= 10;
  }
  return false;
}

void check_and_flag(ll n) {
  ll div = 1e6;
  vll possible_evil;
  while (n % div == n)
    div /= 10;
  div *= 10;
  while (n) {
    if (!is_prime[n])
      return;
    possible_evil.push_back(n);
    n %= div;
    div /= 10;
  }
  cout << possible_evil << endl;

  for (const auto evil : possible_evil) {
    if (!has_zero(evil))
      is_prime[evil]++, evil_num++;
  }
}

void solve() {
  ll n;
  cin >> n;
  // cout << primes << endl;
  for (ll i = num; i >= 0; i--) {
    ll prime = primes[i];
    dbg(prime);
    if (is_prime[n] == 2)
      return;
    check_and_flag(prime);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(1e6 + 5);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
