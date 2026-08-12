#include <cmath>
#include <iomanip>
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

using namespace std;

double solve(int h1, int h2, int threshold, int num_sides) {

  if (threshold == num_sides / 2)
    return (double)h1 / (double)(h1 + h2);

  double res = 1.0 - (num_sides - threshold) / (double)6;
  res = (1 - res) / res;
  return (1.0 - pow(res, h1)) / (1.0 - pow(res, h1 + h2));
}

int hits_allowed(int e, int dmg) {

  int aux = e;
  e = 0;
  while (aux > 0) {
    aux -= dmg;
    e++;
  }
  return e;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int h1, h2, at, dmg;

  while (cin >> h1 >> h2 >> at >> dmg) {

    if (!h1 && !h2 && !at && !dmg)
      break;

    h1 = hits_allowed(h1, dmg);
    h2 = hits_allowed(h2, dmg);

    double res = solve(h1, h2, at, 6);
    std::cout << fixed << setprecision(1) << res * 100 << endl;
  }
  return 0;
}
