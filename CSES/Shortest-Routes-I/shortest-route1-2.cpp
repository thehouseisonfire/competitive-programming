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

vector<ll> solution(ll src, const vector<vector<pll>> &adj) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vector<ll> dist(adj.size(), LLONG_MAX);
  vector<ll> parent(adj.size());

  pq.push({0, src});
  dist[src] = 0;
  parent[src] = -1;

  while (!pq.empty()) {
    const auto curr = pq.top();
    pq.pop();
    const auto &[cul, v] = curr;
    if (dist[v] < cul)
      continue;
    for (const auto &[u, w] : adj[v]) {
      if (dist[u] > w + cul) {
        pq.push({cul + w, u});
        dist[u] = cul + w;
        parent[u] = v;
      }
    }
  }
  return dist;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vector<vector<pll>> adj(n, vector<pll>());
  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  const auto dist = solution(0, adj);
  PRINT_VEC(dist);

  return 0;
}
