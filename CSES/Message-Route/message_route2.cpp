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

vector<int> parent;
vector<int> visited;

void bfs(vector<vector<int>> &adj) {

  const int target = adj.size() - 1;
  visited.resize(adj.size());
  parent.resize(adj.size());
  visited[0] = true;
  parent[0] = -1;

  queue<int> q;

  q.push(0);

  while (!q.empty()) {
    const auto curr = q.front();
    q.pop();
    if (curr == target)
      break;
    for (auto &u : adj[curr]) {
      if (!visited[u]) {
        visited[u] = true;
        q.push(u);
        parent[u] = curr;
      }
    }
  }
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
    adj[b].push_back(a);
    adj[a].push_back(b);
  }

  bfs(adj);
  if (!visited[n - 1]) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector<int> traceback;
  int curr = n - 1, count = 1;
  while (curr != 0) {
    traceback.push_back(curr);
    count++;
    curr = parent[curr];
  }
  traceback.push_back(0);

  cout << count << endl;
  for (size_t i = traceback.size(); i-- > 1;) {
    cout << traceback[i] + 1 << " ";
  }
  cout << traceback[0] + 1 << endl;

  return 0;
}
