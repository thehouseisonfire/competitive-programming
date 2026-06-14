#include <iostream>
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

const ll MAX = 50001;
vector<ll> adj[MAX];
pll pares[MAX / 2 + 1];
ll depth[MAX], parent[MAX];
bool visited[MAX];

void dfs(const ll v, const ll p) {

  visited[v] = true;
  parent[v] = p;

  for (const auto neighbor : adj[v]) {
    if (!visited[neighbor]) {
      depth[neighbor] = depth[v] + 1;
      dfs(neighbor, v);
    }
  }
}

ll lca(ll u, ll v) {
  while (depth[u] > depth[v])
    u = parent[u];
  while (depth[v] > depth[u])
    v = parent[v];
  while (u != v) {
    u = parent[u];
    v = parent[v];
  }
  return u;
}

ll calc_dist(const ll u, const ll v) {
  ll anc = lca(u, v);
  return depth[u] + depth[v] - 2 * depth[anc];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  for (size_t i = 1; i <= n; i++) {
    ll aux;
    cin >> aux;
    auto &[c1, c2] = pares[aux];
    if (!c1)
      c1 = i;
    else
      c2 = i;
  }

  for (size_t i = 1; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, -1);

  ll sum = 0;

  for (size_t i = 1; i <= n >> 1; i++) {
    const auto &[c1, c2] = pares[i];
    sum += calc_dist(c1, c2);
  }

  cout << sum << endl;

  return 0;
}
