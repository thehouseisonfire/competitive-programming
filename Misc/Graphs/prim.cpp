#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
using pll = pair<ll, int>;

ll solution(const vector<vector<pll>> &adj) {
  int n = adj.size();

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vector<bool> used(n);

  pq.push({0, 0});

  ll cost = 0;
  int visited = 0;

  while (!pq.empty()) {
    auto [weight, u] = pq.top();
    pq.pop();

    if (used[u])
      continue;

    used[u] = true;
    cost += weight;
    visited++;

    for (auto [next_weight, v] : adj[u])
      if (!used[v])
        pq.push({next_weight, v});
  }

  return visited == n ? cost : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<pll>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    ll weight;
    cin >> u >> v >> weight;
    u--, v--;

    adj[u].push_back({weight, v});
    adj[v].push_back({weight, u});
  }

  ll result = solution(adj);

  if (result == -1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << result << endl;

  return 0;
}
