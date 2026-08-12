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

void search(const pi &pos, vector<vector<char>> &mtx) {
  const auto [x, y] = pos;
  const auto w = mtx.size();
  const auto h = mtx[0].size();
  if (x == w || y == h || x == -1 || y == -1)
    return;
  if (mtx[x][y] != '.')
    return;

  mtx[x][y] = 'T';
  search({x - 1, y}, mtx);
  search({x + 1, y}, mtx);
  search({x, y - 1}, mtx);
  search({x, y + 1}, mtx);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int count = 0;
  vector<vector<char>> mtx(n, vector<char>(m));

  for (auto &vec : mtx)
    for (auto &pos : vec)
      cin >> pos;

  for (int i = 0; i < mtx.size(); i++)
    for (int j = 0; j < mtx[i].size(); j++)
      if (mtx[i][j] == '.') {
        count++;
        search({i, j}, mtx);
      }
  cout << count << endl;

  return 0;
}
