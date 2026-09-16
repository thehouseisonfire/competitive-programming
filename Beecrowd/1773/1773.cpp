#include <cmath>
#include <iostream>
#include <queue>
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

int main() {

  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> adj(n);
    int i = m;
    while (i--) {
      int w, u;
      cin >> w >> u;
      w--, u--;
      adj[u].push_back(w);
      adj[w].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<bool> reachable(n, false);
    vector<int> locations(n);
    vector<vector<int>> unlocks(n);
    for (ll i = 1; i < n; i++) {
      cin >> locations[i];
      locations[i]--;
      unlocks[locations[i]].push_back(i);
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    reachable[0] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int room : unlocks[u]) {
        if (reachable[room] && !visited[room]) {
          visited[room] = true;
          q.push(room);
        }
      }

      for (int neighbor : adj[u]) {
        if (visited[neighbor])
          continue;

        reachable[neighbor] = true;

        if (visited[locations[neighbor]]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    bool flag = true;
    for (const auto &pos : visited)
      if (!pos) {
        flag = false;
        break;
      }
    cout << (flag ? "sim" : "nao") << endl;
  }
  return 0;
}
