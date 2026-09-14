// https://codeforces.com/gym/106073/problem/K

#include <iostream>

#define u8 unsigned char
#define hd short int
#define hu short unsigned
#define lu unsigned
#define ll long long
#define llu long long unsigned
#define float double
#define double long double
#define pi pair<int, int>
#define pll pair<ll, ll>

#define INF 2147483647
#define HINF INF >> 1
#define MOD 1000000007
#define ASCII_NUMBER_OFFSET '0'
#define ASCII_UPPERCASE_OFFSET 'A'
#define ASCII_LOWERCASE_OFFSET 'a'

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define PI(x) cout << x.first << " " << x.second << endl
#define DUO(x, y) cout << x << " " << y << endl

using namespace std;

ll factors(ll n) {
  ll res = 0;

  while (n) {
    n /= 2;
    res += n;
  }

  return res;
}

ll power(ll a, ll b) {
  ll res = 1;

  while (b) {
    if (b & 1)
      res = res * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll a, b;
  cin >> a >> b;

  ll la = max(0LL, a - 130);
  ll lb = max(0LL, b - 130);
  ll mini = 0;

  for (ll i = la; i < a; i++) {
    for (ll j = lb; j < b; j++) {
      const ll g = factors(i + j) - factors(i) - factors(j);
      const ll f = g - i - j;

      mini = min(mini, f);
    }
  }

  cout << power(2, -mini + 1) << endl;

  return 0;
}
