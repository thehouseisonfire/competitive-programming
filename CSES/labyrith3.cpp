#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

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

const int MAXN = 1005;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
pi parent[MAXN][MAXN];
bool visited[MAXN][MAXN];

int n, m;
pi start, end_pos;

// Directions: Up, Down, Left, Right
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' &&
         !visited[x][y];
}

string reconstruct_path() {
  string path;
  pi cur = end_pos;
  while (cur != start) {
    pi prev = parent[cur.first][cur.second];
    for (int i = 0; i < 4; ++i) {
      int nx = prev.first + dx[i];
      int ny = prev.second + dy[i];
      if (nx == cur.first && ny == cur.second) {
        path += dir_char[i];
        break;
      }
    }
    cur = prev;
  }
  reverse(path.begin(), path.end());
  return path;
}

bool bfs() {
  queue<pi> q;
  q.push(start);
  visited[start.first][start.second] = true;
  dist[start.first][start.second] = 0;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == end_pos.first && y == end_pos.second) {
      return true;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (valid(nx, ny)) {
        visited[nx][ny] = true;
        parent[nx][ny] = {x, y};
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        start = {i, j};
      if (grid[i][j] == 'B')
        end_pos = {i, j};
    }
  }

  if (bfs()) {
    cout << "YES\n";
    cout << dist[end_pos.first][end_pos.second] << "\n";
    cout << reconstruct_path() << "\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
