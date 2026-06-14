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

// const int color_size = 2;
// int colors[color_size] = {1, 2};

// vector<vector<int>> color_bfs(const vector<vector<int>> &adj) {
//   vector<int> visited[color_size];
//   vector<vector<int>> res(adj.size(), vector<int>(color_size));
//   return res;
// }
vector<int> color_bfs(const vector<vector<int>> &adj) {
  vector<int> visited(adj.size());

  for (int i = 0; i < adj.size(); i++) {
    if (visited[i])
      continue;
    visited[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      const auto curr = q.front();
      q.pop();
      const auto next_color = (visited[curr] % 2) + 1;
      for (const auto &u : adj[curr]) {
        if (!visited[u]) {
          visited[u] = next_color;
          q.push(u);
        } else if (visited[u] == visited[curr]) {
          visited[0] = 0;
          return visited;
        }
      }
    }
  }
  return visited;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  const auto colors = color_bfs(adj);
  for (const auto &pos : colors) {
    if (pos == 0) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    cout << colors[i] << " ";
  }
  cout << colors[n - 1] << endl;

  return 0;
}
