#include <algorithm>
#include <iostream>
#include <queue>

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

const int MAX = 1005;

int n, m;
char mtx[MAX][MAX];
char visited[MAX][MAX];
pi parent[MAX][MAX];

pi start_pos, end_pos = {-1, -1};

#define START_SYMBOL 'A'
#define END_SYMBOL 'B'
#define WALL '#'

bool flag = false;

bool valid(int x, int y) {
  return !(x < 0 || y < 0 || x == n || y == m || mtx[x][y] == WALL);
}

string traceback() {
  string res;

  auto prev = end_pos;
  while (prev != start_pos) {
    const auto [px, py] = prev;
    const auto [x, y] = parent[px][py];
    // DUO(x, y);
    // DUO(px, py);
    if (px == x + 1 && py == y)
      res.push_back('D');
    if (px == x - 1 && py == y)
      res.push_back('U');
    if (px == x && py == y + 1)
      res.push_back('R');
    if (px == x && py == y - 1)
      res.push_back('L');
    prev = {x, y};
  }

  return res;
}

void bfs() {
  queue<pi> q;
  q.push(start_pos);
  visited[start_pos.first][start_pos.second] = true;
  while (!q.empty()) {
    const auto curr = q.front();
    q.pop();
    const auto [x, y] = curr;
    if (curr == end_pos) {
      flag = true;
      return;
    }
    const pi options[] = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
    for (const auto [nx, ny] : options) {
      if (valid(nx, ny) && !visited[nx][ny]) {
        visited[nx][ny] = true;
        parent[nx][ny] = {x, y};
        q.push({nx, ny});
      }
    }
  }
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char aux;
      cin >> aux;
      mtx[i][j] = aux;
      if (aux == START_SYMBOL)
        start_pos = {i, j};
      if (aux == END_SYMBOL)
        end_pos = {i, j};
    }
  }

  bfs();
  if (!flag) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  string res = traceback();
  reverse(res.begin(), res.end());

  cout << res.length() << endl;
  cout << res << endl;

  return 0;
}
