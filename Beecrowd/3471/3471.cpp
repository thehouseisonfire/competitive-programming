#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

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
  cout << endl;

#define PRINT_DUO_VEC(v)                                                       \
  for (const auto &pos : v) {                                                  \
    cout << pos.first << " " << pos.second << endl;                            \
  }                                                                            \
  cout << endl;

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

llu fibonacci(llu n) {
  return (pow(1 + sqrt(5), n) - pow(1 - sqrt(5), n)) / (pow(2, n) * sqrt(5));
}

int main() {
  int n, m;
  cin >> n >> m;
  llu o = __gcd(n, m);
  vector<llu> v;
  v.push_back(0);
  v.push_back(1);
  llu i = 2, a = 0, b = 1;
  while (i <= o) {
    llu c = a + b;
    v.push_back(c);
    a = b;
    b = c;
    i++;
  }
  PRINT_VEC(v);
  llu gcd = v[o];
  cout << v[o];
  while (i <= gcd) {
    llu c = a + b;
    v.push_back(c);
    a = b;
    b = c;
    i++;
  }

  if (i == 2)
    i = 1;
  // cout << (o == c ? i : -1) << endl;
  return 0;
}
