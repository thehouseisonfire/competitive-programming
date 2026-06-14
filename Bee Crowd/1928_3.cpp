#include <cmath>
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

int l;

vector<vector<int>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

const ll MAX = 50005;
ll depth[MAX];

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  for (int u : adj[v]) {
    if (u != p) {
      depth[u] = depth[v] + 1;
      dfs(u, v);
    }
  }
  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

void preprocess(int root, int n) {
  timer = 0;
  tin.resize(n);
  tout.resize(n);
  l = ceil(log2(n));
  up.assign(n + 1, vector<int>(l + 1));
  dfs(root, root);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  adj.resize(n);
  vector<pll> pares((n >> 1));

  for (size_t i = 0; i < n; i++) {
    ll aux;
    cin >> aux;
    aux--;
    auto &[c1, c2] = pares[aux];
    if (!c1)
      c1 = i;
    else
      c2 = i;
  }

  for (size_t i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  preprocess(0, n);

  ll sum = 0;

  for (size_t i = 0; i < n >> 1; i++) {
    const auto &[c1, c2] = pares[i];
    ll ancestral = lca(c1, c2);

    sum += depth[c1] + depth[c2] - 2 * depth[ancestral];
  }

  cout << sum << endl;

  return 0;
}
