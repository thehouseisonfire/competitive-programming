#include <algorithm>
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

#define hero 'A'
#define end_char 'B'
#define monster 'M'
#define WALL '#'

const int MAX = 1005;

pi hero_pos = {-1, -1};

int n, m;
char mtx[MAX][MAX];
pi parent[MAX][MAX];
int hdist[MAX][MAX];
int mdist[MAX][MAX];
bool visited[MAX][MAX];

void start() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      hdist[i][j] = INF;
      mdist[i][j] = INF;
    }
  }
}

bool valid(int x, int y) {
  return !(x < 0 || y < 0 || x == n || y == m || mtx[x][y] == WALL);
}

void hbfs() {
  queue<pi> q;
  q.push(hero_pos);
  visited[hero_pos.first][hero_pos.second] = true;
  while (!q.empty()) {
    const auto curr = q.front();
    q.pop();
    const auto [x, y] = curr;
    const pi options[] = {{x + 1, y}, {x, y + 1}, {x - 1, y}, {x, y - 1}};
    for (const auto [nx, ny] : options) {
      if (valid(nx, ny) && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = true;
        parent[nx][ny] = curr;
        hdist[nx][ny] = hdist[x][y] + 1;
      }
    }
  }
}

void mbfs(const vector<pi> &starts) {
  queue<pi> q;
  for (const auto start : starts)
    q.push(start);
  while (!q.empty()) {
    const auto curr = q.front();
    q.pop();
    const auto [x, y] = curr;
    const pi options[] = {{x + 1, y}, {x, y + 1}, {x - 1, y}, {x, y - 1}};
    for (const auto [nx, ny] : options) {
      if (valid(nx, ny) && mtx[nx][ny] != 'M' && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = true;
        mdist[nx][ny] = mdist[x][y] + 1;
      }
    }
  }
}

string traceback(int x, int y) {
  string res;
  pi prev = {x, y};
  while (prev != hero_pos) {
    const auto [px, py] = prev;
    const auto curr = parent[px][py];
    const auto [x, y] = curr;
    if (x + 1 == px && y == py)
      res.push_back('D');
    if (x - 1 == px && y == py)
      res.push_back('U');
    if (x == px && y + 1 == py)
      res.push_back('R');
    if (x == px && y - 1 == py)
      res.push_back('L');
    prev = curr;
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  start();
  vector<pi> monsters;
  vector<pi> exits;
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char aux;
      cin >> aux;
      mtx[i][j] = aux;
      if (aux == hero)
        hero_pos = {i, j};
      if (aux == monster)
        monsters.push_back({i, j});
      if ((i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
        if (aux == '.')
          exits.push_back({i, j});
        if (aux == 'A')
          flag = true;
      }
    }
  }

  if (flag) {
    cout << "YES" << endl << 0 << endl;
    return 0;
  }

  if (!exits.size()) {
    cout << "NO" << endl;
    return 0;
  }

  hbfs();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }

  mbfs(monsters);
  for (const auto [x, y] : exits) {
    cout << endl;

    if (hdist[x][y] < mdist[x][y]) {
      auto res = traceback(x, y);
      reverse(res.begin(), res.end());
      cout << "YES" << endl;
      cout << res.size() << endl;
      cout << res << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}
