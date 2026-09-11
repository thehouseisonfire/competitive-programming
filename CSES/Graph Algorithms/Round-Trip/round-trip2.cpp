#include <iostream>
#include <stack>
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

vector<int> parent;
vector<int> visited;

vector<int> dfs(int src, const vector<vector<int>> &adj) {

  stack<int> st;

  st.push(src);
  visited[src] = 1;
  parent[src] = -1;

  while (!st.empty()) {
    bool found_unvisited = false;
    const auto v = st.top();
    for (const auto &u : adj[v]) {
      if (!visited[u]) {
        st.push(u);
        visited[u] = 1;
        parent[u] = v;
        found_unvisited = true;
        break;
      } else if (visited[u] == 1 && u != parent[v]) {
        vector<int> path;
        path.push_back(u);
        int curr = v;
        while (curr != -1 && curr != u) {
          path.push_back(curr);
          curr = parent[curr];
        }
        path.push_back(u);
        return path;
      }
    }
    if (!found_unvisited) {
      visited[v] = 2;
      st.pop();
    }
  }
  return {};
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  visited.resize(n);
  visited.assign(n, 0);
  parent.resize(n);
  parent.assign(n, -1);

  vector<vector<int>> adj(n, vector<int>());

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      const auto path = dfs(i, adj);
      if (path.empty())
        continue;
      cout << path.size() << endl;
      for (const auto &pos : path)
        cout << pos + 1 << " ";
      cout << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
