#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

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

#define WALL '#'

const int MAXN = 1005;
char mtx[MAXN][MAXN];
pi parent[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m;

pi START, END = {-1, -1};

bool check(int x, int y) {
  return !(x < 0 || y < 0 || x == n || y == m || mtx[x][y] == WALL);
}

string traceback() {
  string res;
  auto prev = END;
  while (prev != START) {
    const auto [px, py] = prev;
    const auto &[x, y] = parent[px][py];

    if (x + 1 == px && y == py)
      res.push_back('D');
    else if (x - 1 == px && y == py)
      res.push_back('U');
    else if (x == px && y + 1 == py)
      res.push_back('R');
    else if (x == px && y - 1 == py)
      res.push_back('L');
    prev = {x, y};
  }
  return res;
}

void bfs(const pi start) {

  queue<pi> q;

  visited[start.first][start.second] = true;
  q.push(start);

  while (!q.empty()) {

    auto [x, y] = q.front();
    q.pop();

    if (mtx[x][y] == 'B') {
      END = {x, y};
      break;
    }

    pi options[4] = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};

    for (const auto pos : options) {
      if (!visited[pos.first][pos.second] && check(pos.first, pos.second)) {
        visited[pos.first][pos.second] = true;
        parent[pos.first][pos.second] = {x, y};
        q.push(pos);
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
      if (aux == 'A')
        START = {i, j};
    }
  }
  bfs(START);
  if (END.first == -1 && END.second == -1) {
    cout << "NO" << endl;
    return 0;
  }

  string res = traceback();
  cout << "YES" << endl;
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  cout << res << endl;

  return 0;
}
