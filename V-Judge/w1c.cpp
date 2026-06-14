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

void rotate(vector<string> &v, int n) {
  vector<string> aux(n, string(n, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      auto curr = v[i][j];
      if (curr == '>')
        curr = 'v';
      else if (curr == 'v')
        curr = '<';
      else if (curr == '<')
        curr = '^';
      else if (curr == '^')
        curr = '>';

      aux[j][n - 1 - i] = curr;
    }
  }
  v = aux;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  string s;
  cin >> n >> s;
  vector<string> v(n);
  INPUT_VEC(v);

  int count = 0;
  for (const auto c : s)
    count += (c == 'R') ? 1 : -1;

  count %= 4;
  if (count < 0)
    count += 4;

  while (count--)
    rotate(v, n);

  for (const auto &str : v)
    cout << str << endl;

  return 0;
}
