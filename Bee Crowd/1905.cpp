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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool bounded(int x, int y, const vector<vector<int>> &grid) {
  return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

bool bfs(vector<vector<int>> &grid) {
  queue<pll> q;
  vector<vector<bool>> visited(5, vector<bool>(5, false));

  q.push({0, 0});
  visited[0][0] = true;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == 4 && y == 4)
      return true;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!bounded(nx, ny, grid))
        continue;
      if (visited[nx][ny] || grid[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;

  while (t--) {
    vector<vector<int>> grid(5, vector<int>(5));

    for (int i = 0; i < 5; ++i) {
      INPUT_VEC(grid[i]);
    }

    if (grid[0][0] == 1 || grid[4][4] == 1 || !bfs(grid)) {
      cout << "ROBBERS" << endl;
    } else {
      cout << "COPS" << endl;
    }
  }

  return 0;
}
