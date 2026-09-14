// https://codeforces.com/problemset/problem/1490/B

#include <iostream>
#include <vector>

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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    vector<int> v(m);
    int a = 0, b = 0, c = 0;
    for (auto &pos : v) {
      int aux;
      cin >> aux;
      pos = aux;
      int rem = aux % 3;
      if (!rem)
        a++;
      if (rem == 1)
        b++;
      if (rem == 2)
        c++;
    }

    int count = 0, extra = 0;
    int target = m / 3;

    while (a != target || b != target || c != target) {
      if (a > target) {
        extra = a - target;
        count += extra;
        b += extra;
        a = target;
      }
      if (b > target) {
        extra = b - target;
        count += extra;
        c += extra;
        b = target;
      }
      if (c > target) {
        extra = c - target;
        count += extra;
        a += extra;
        c = target;
      }
    }
    cout << count << endl;
  }
  return 0;
}
