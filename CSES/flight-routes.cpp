#include <array>
#include <climits>
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

ll djikstra(const int src, const int target, const vector<vector<pll>> &adj) {

  vector<array<ll, 3>> dist(adj.size(), {LLONG_MAX, 0, false});
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  dist[src] = {0, 0};
  pq.push({0, src});

  while (!pq.empty()) {
    const auto [cul, v] = pq.top();
    pq.pop();
    if (dist[v][0] < cul)
      continue;

    for (const auto [w, u] : adj[v]) {
      if (dist[u][0] > cul + w) {
        dist[u][0] = cul + w;
        dist[u][1] = max(dist[v][1], w);
        pq.push({cul + w, u});
      }
    }
  }
  // PRINT_DUO_VEC(dist);
  const auto [sum, biggest] = dist[target];
  return sum - biggest + (biggest >> 1);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<pll>> adj(n, vector<pll>());
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({c, b});
  }

  const auto res = djikstra(0, n - 1, adj);
  cout << res << endl;

  return 0;
}
