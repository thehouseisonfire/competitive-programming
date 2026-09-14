#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using vi = vector<int>;

int solution(const vector<vi> &adj) {
  int n = adj.size();
  int min_cycle_length = n + 1;

  for (int i = 0; i < n; i++) {
    vi dist(n, -1);
    vi parent(n, -1);
    queue<int> q;

    dist[i] = 0;
    q.push(i);

    while (!q.empty()) {
      const auto v = q.front();
      q.pop();

      for (const auto u : adj[v]) {
        if (dist[u] == -1) {
          dist[u] = dist[v] + 1;
          parent[u] = v;
          q.push(u);
        } else if (parent[v] != u) {
          int cycle_length = dist[v] + dist[u] + 1;
          min_cycle_length = min(min_cycle_length, cycle_length);
        }
      }
    }
  }

  return min_cycle_length == n + 1 ? -1 : min_cycle_length;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << solution(adj) << endl;

  return 0;
}
