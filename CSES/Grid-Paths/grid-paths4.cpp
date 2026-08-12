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
  {                                                                            \
    for (const auto &pos : v) {                                                \
      cout << pos << " ";                                                      \
    }                                                                          \
    cout << endl;                                                              \
  }

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

const int trap = -2;
const int untreaded = -1;

int solution(const pi pos, vector<vector<int>> &results) {
  const auto [x, y] = pos;
  const auto size = results.size();
  if (x < 0 || x >= size || y < 0 || y >= size)
    return 0;
  if (results[x][y] == trap)
    return 0;
  if (results[x][y] != untreaded)
    return results[x][y];
  if (x == size - 1 && y == size - 1)
    return 1;

  ll right = solution({x + 1, y}, results);
  ll down = solution({x, y + 1}, results);
  return results[x][y] = (right + down) % MOD;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (auto &vec : v) {
    for (auto &pos : vec) {
      char aux;
      cin >> aux;
      pos = aux == '*' ? trap : untreaded;
    }
  }
  cout << solution({0, 0}, v) << endl;
  return 0;
}
