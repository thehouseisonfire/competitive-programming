#include <cmath>
#include <iostream>
#include <map>
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

ll timee = 0;

vector<vll> adj;
vector<ll> tin;
vector<ll> pos;
vector<bool> visited;
vector<int> sub;

void dfs(ll curr) {

  pos[curr] = timee;
  tin[timee] = curr;
  timee++;

  visited[curr] = true;
  sub[curr] = 1;
  for (const auto filho : adj[curr]) {
    if (visited[filho])
      continue;
    dfs(filho);
    sub[curr] += sub[filho];
  }
}

void solve() {
  ll n, q;
  cin >> n >> q;

  adj.resize(n);
  tin.resize(n);
  pos.resize(n);
  visited.resize(n);
  sub.resize(n);

  for (ll i = 1, x; i < n; i++) {
    cin >> x;
    x--;
    adj[x].push_back(i);
  }

  dfs(0);

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    if (sub[a] - 1 < b) {
      cout << -1 << endl;
      continue;
    }
    cout << tin[pos[a] + b] + 1 << endl;
  }
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
