#include <iostream>
#include <vector>

#pragma GCC optimize("O3")
#pragma GCC target("avx2,tune=native")

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
// #define ASCII_NUMBER_OFFSET 48
// #define ASCII_UPPERCASE_OFFSET 65
// #define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define PI(x) cout << x.first << " " << x.second << endl
#define DUO(x, y) cout << x << " " << y << endl

#define PRINT_VEC(v)                                                           \
  for (const auto &pos : v) {                                                  \
    cout << pos << " ";                                                        \
  }                                                                            \
  \ cout << endl;

#define PRINT_DUO_VEC(v)                                                       \
  for (const auto &pos : v) {                                                  \
    cout << pos.first << " " << pos.second << endl;                            \
  }                                                                            \
  \ cout << endl;

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

#define MAX 65535

vector<ll> primes;

void sieve() {
  vector<bool> is_prime(MAX + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAX; ++i) {
    if (!is_prime[i])
      continue;
    primes.push_back(i);
    for (int j = i * 2; j <= MAX; j += i)
      is_prime[j] = false;
  }
}

const ll compute_totient(ll n) {
  ll result = n;
  ll original_n = n;

  for (const auto p : primes) {
    // if (p * p > n)  break;
    if (n % p == 0) {
      while (n % p == 0)
        n /= p;
      result -= result / p;
    }
  }

  if (n > 1)
    result -= result / n;

  return result;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  sieve();

  ll n;
  while (cin >> n) {
    ll res = compute_totient(n);
    cout << (res >> 1) << endl;
  }

  return 0;
}
