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

int solution(const pi pos, vector<vector<pair<bool, int>>> &mtx) {
  const auto size = mtx.size();
  const auto [h, v] = pos;
  if (size <= h || size <= v)
    return 0;
  const auto [trap, res] = mtx[h][v];
  if (trap)
    return 0;
  if (res != -1)
    return res;
  if (h == size - 1 && v == size - 1) {
    return 1;
  }

  ll down = 0, right = 0;
  down = solution({h + 1, v}, mtx) % MOD;
  right = solution({h, v + 1}, mtx) % MOD;
  ll result = (down + right) % MOD;
  mtx[h][v].second = result;
  return result;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<pair<bool, int>>> v(n, vector<pair<bool, int>>(n));
  for (auto &vec : v)
    for (auto &pos : vec) {
      char aux;
      cin >> aux;
      pos = {aux == '*', -1};
    }

  ll res = solution({0, 0}, v);
  cout << (res != -1 ? res : 0) << endl;

  // for (auto &vec : v) {
  //   for (auto &pos : vec)
  //     cout << pos.second << " ";
  //   cout << endl;
  // }

  return 0;
}
