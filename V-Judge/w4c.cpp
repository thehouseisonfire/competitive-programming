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
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  INPUT_VEC(v);
  int a = -1, b = -1, j, k;
  for (int i = 0; i < n; i++) {
    if (v[i] && a == -1)
      a = v[i], j = i;
    else if (v[i] && b == -1) {
      b = v[i], k = i;
      break;
    };
  }

  if (a == -1) {
    cout << -1 << endl;
    return 0;
  }
  if (a >= m) {
    for (int i = 0; i < m - 1; i++)
      cout << j + 1 << " ";
    cout << j + 1 << endl;
    return 0;
  }
  if (b == -1) {
    cout << -1 << endl;
    return 0;
  }

  int d = 0;
  bool flag = true;
  while (d < m) {
    for (int i = 0; i < a && d < m; i++) {
      if (!flag)
        cout << " ";
      cout << j + 1;
      d++;
      flag = false;
    }
    if (d < m) {
      for (int i = 0; i < b && d < m; i++) {
        if (!flag)
          cout << " ";
        cout << k + 1;
        d++;
        flag = false;
      }
    }
  }
  cout << endl;

  return 0;
}
