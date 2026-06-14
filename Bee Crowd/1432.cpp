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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int solveTrible(string &s) {
  if (s == "***")
    return 2;
  if (s == "**0")
    return 1;
  if (s == "**1")
    return 1;
  if (s == "*0*")
    return 1;
  if (s == "*00")
    return 1;
  if (s == "*01")
    return 0;
  if (s == "*1*")
    return 0;
  if (s == "*10")
    return 0;
  if (s == "*11")
    return 0;
  if (s == "0**")
    return 0;
  if (s == "0*0")
    return 0;
  if (s == "0*1")
    return 0;
  if (s == "00*")
    return 0;
  if (s == "000")
    return 0;
  if (s == "001")
    return 0;
  if (s == "01*")
    return 0;
  if (s == "010")
    return 0;
  if (s == "011")
    return 0;
  if (s == "1**")
    return 0;
  if (s == "1*0")
    return 0;
  if (s == "1*1")
    return 0;
  if (s == "10*")
    return 0;
  if (s == "100")
    return 0;
  if (s == "101")
    return 0;
  if (s == "11*")
    return 0;
  if (s == "110")
    return 0;
  if (s == "111")
    return 0;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  int i = 0;
  while (cin >> n && n != 0) {
    string s;
    cin >> s;
    i++;
    cout << "Case << " << i << ": " << res << endl;
  }

  return 0;
}
