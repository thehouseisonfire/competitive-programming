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

int solution(const pi &position, vector<vector<ll>> &mtx) {
  const auto [x, y] = position;
  if (x == mtx.size() || y == mtx.size())
    return 0;
  if (mtx[x][y] == -2)
    return 0;
  if (mtx[x][y] != -1)
    return mtx[x][y];

  ll size = mtx.size() - 1;
  ll sum = x == size && y == size;
  sum +=
      ((solution({x + 1, y}, mtx) % MOD) + (solution({x, y + 1}, mtx) % MOD)) %
      MOD;
  mtx[x][y] = sum;
  return sum;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<ll>> v(n, vector<ll>(n));
  for (auto &vec : v)
    for (auto &pos : vec) {
      char aux;
      cin >> aux;
      pos = aux == '*' ? -2 : -1;
    }
  cout << solution({0, 0}, v) << endl;

  return 0;
}
