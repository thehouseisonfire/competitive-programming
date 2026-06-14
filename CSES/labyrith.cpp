#include <iostream>
#include <queue>
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

#define start_char 'A'
#define end_char 'B'
#define visited '*'
#define wall '#'

void bfs(const pi start, vector<vector<char>> &mtx) {

  // create an array to store the traversal
  vector<pi> res;

  // Create a queue for BFS
  queue<pi> q;

  q.push(start);

  // Iterate over the queue
  while (!q.empty()) {

    auto [x, y] = q.front();
    q.pop();

    if (x < 0 || y < 0 || x == mtx.size() || y == mtx[0].size() ||
        mtx[x][y] == wall || mtx[x][y] == visited)
      continue;

    res.push_back({x, y});
    if (mtx[x][y] == end_char)
      break;
    mtx[x][y] = visited;

    q.push({x + 1, y});
    q.push({x, y + 1});
    q.push({x - 1, y});
    q.push({x, y - 1});
  }
  for (const auto a : res)
    DUO(a.first, a.second);

  auto prev = res[0];
  for (ll i = 1; i < res.size(); i++) {
    const auto [x, y] = res[i];
    const auto [px, py] = prev;
    if (x < px)
      cout << 'U';
    if (y < py)
      cout << 'L';
    if (px < x)
      cout << 'D';
    if (py < y)
      cout << 'R';
    prev = {x, y};
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> mtx(n, vector<char>(m));
  pi start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mtx[i][j];
      if (mtx[i][j] == start_char)
        start = {i, j};
    }
  }

  bfs(start, mtx);

  return 0;
}
