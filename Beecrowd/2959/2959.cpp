#include <iostream>
#include <vector>

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

using namespace std;
#define DUO(x, y) cout << x << " " << y << endl

const int INF = 1e9;

vector<vector<int>> floydWarshall(vector<vector<int>> &graph) {
  int n = graph.size();

  vector<vector<int>> dist = graph;

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INF && dist[k][j] != INF &&
            dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  return dist;
}

// void print(vector<vector<int>> &dist) {
//   int n = dist.size();
//
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       if (dist[i][j] == INF)
//         cout << "INF\t";
//       else
//         cout << dist[i][j] << "\t";
//     }
//     cout << endl;
//   }
// }

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<vector<int>> v(n, vector<int>(n, INF));
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      if (i == k)
        v[i][k] = 0;

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a][b] = 1;
    v[b][a] = 1;
  }
  auto dist = floydWarshall(v);
  while (p--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << (dist[a][b] == INF ? "Deu ruim" : "Lets que lets") << endl;
  }

  return 0;
}
