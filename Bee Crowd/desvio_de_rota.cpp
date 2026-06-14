#include <iostream>
#include <limits.h>
#include <vector>

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
#define pi pair<int, int>

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

int minDistance(vector<int> &dist, bool sptSet[]) {

  int min = INT_MAX, min_index;

  for (int v = 0; v < dist.size(); v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

void dijkstra(vector<vector<int>> &graph, vector<int> &dist, int src) {

  bool sptSet[dist.size()];
  for (int i = 0; i < dist.size(); i++)
    dist[i] = INT_MAX, sptSet[i] = false;
  dist[src] = 0;

  for (int count = 0; count < dist.size() - 1; count++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;
    for (int v = 0; v < dist.size(); v++)
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
}
// k = 2
// c = 1
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, c, k;
  while (cin >> n >> m >> c >> k) {
    if (!n && !m && !c && !k)
      return 0;
    vector<vector<int>> mtx(n, vector<int>(n, 0));
    int v, u, p;
    while (m--) {
      cin >> v >> u >> p;
      if (u < v)
        swap(u, v);
      if (u < c && v + 1 == u) {
        mtx[v][u] = p;
      } else if (v < c && c - 1 < u) {
        mtx[u][v] = p;
      } else if (v > c - 1 && u > c - 1) {
        mtx[v][u] = p;
        mtx[u][v] = p;
      }
    }
    vector<int> dist(n);
    dijkstra(mtx, dist, k);
    for (const auto &v : mtx) {
      PRINT_VEC(v)
    }
    cout << endl;
    PRINT_VEC(dist)
    cout << dist[c - 1] << endl;
  }
}
