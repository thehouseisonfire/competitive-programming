#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MAX_N = 2505;

vector<vector<pll>> adj(MAX_N);
vector<vector<ll>> rev(MAX_N);
bool from_source[MAX_N];
bool to_target[MAX_N];

int n;

ll dist[MAX_N];

void bfs(ll src) {
  queue<ll> q;
  q.push(src);
  from_source[src] = true;
  while (!q.empty()) {
    const auto v = q.front();
    q.pop();
    for (const auto &[w, u] : adj[v]) {
      if (from_source[u])
        continue;
      from_source[u] = true;
      q.push(u);
    }
  }
}

void bfs2(ll dest) {
  queue<ll> q;
  q.push(dest);
  to_target[dest] = true;
  while (!q.empty()) {
    const auto v = q.front();
    q.pop();
    for (const auto u : rev[v]) {
      if (to_target[u])
        continue;
      to_target[u] = true;
      q.push(u);
    }
  }
}

bool bellman(const ll src) {

  dist[src] = 0;

  for (ll i = 0; i < n - 1; i++) {
    for (ll v = 0; v < n; v++) {
      if (dist[v] != LLONG_MIN) {
        for (const auto &[w, u] : adj[v]) {
          if (dist[u] < w + dist[v])
            dist[u] = dist[v] + w;
        }
      }
    }
  }

  for (ll v = 0; v < n; v++) {
    if (dist[v] != LLONG_MIN) {
      for (const auto &[w, u] : adj[v]) {
        if (dist[u] < w + dist[v])
          if (from_source[u] && to_target[u])
            return true;
      }
    }
  }

  return false;
}

void start() {
  for (ll i = 0; i < MAX_N; i++) {
    dist[i] = LLONG_MIN;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  start();
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({c, b});
    rev[b].push_back(a);
  }

  bfs(0);
  bfs2(n - 1);

  const auto pos_cycle = bellman(0);
  if (pos_cycle) {
    cout << -1 << endl;
  } else {
    cout << dist[n - 1] << endl;
  }

  return 0;
}
