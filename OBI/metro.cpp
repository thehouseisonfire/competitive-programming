// https://olimpiada.ic.unicamp.br/pratique/ps/2015/f1/metro/#

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v)
    is >> x;
  return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size(); ++i)
    os << (i > 0 ? " " : "") << v[i];
  return os;
}

#define dbg(x) cerr << #x << " = " << (x) << endl
#define all(x) (x).begin(), (x).end()

ll n;
ll bridge_count = 0;
void IS_BRIDGE(int v, int to) { bridge_count++; }
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<ll> grau;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
  visited[v] = true;
  tin[v] = low[v] = timer++;
  bool parent_skipped = false;
  for (int to : adj[v]) {
    if (to == p && !parent_skipped) {
      parent_skipped = true;
      continue;
    }
    if (visited[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v])
        IS_BRIDGE(v, to);
    }
  }
}

void find_bridges() {
  timer = 0;
  visited.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!visited[i])
      dfs(i);
  }
}

void solve() {
  ll m;
  cin >> n >> m;
  adj.resize(n);
  adj2.resize(n);
  grau.resize(n);
  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    grau[a]++, grau[b]++;
  }
  ll big = 0, vertice_big;
  for (ll i = 0; i < n; i++)
    if (big < grau[i])
      big = grau[i], vertice_big = i;

  for (ll i = 0; i < n; i++) {
    for (auto j : adj[i]) {
      if (i == vertice_big)
        continue;
      if (j == vertice_big)
        continue;
      adj2[i].push_back(j);
    }
  }

  adj = adj2;

  find_bridges();

  cout << n - 1 - bridge_count << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
