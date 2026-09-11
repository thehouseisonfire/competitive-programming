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

using vc = vector<char>;
void paint(vector<vc> &v, ll x, ll y, ll n, ll m) {
  queue<pll> q;
  q.push({x, y});
  while (!q.empty()) {
    const auto [x, y] = q.front();
    q.pop();
    if (x > 0 && v[x - 1][y] == '.')
      q.push({x - 1, y}), v[x - 1][y] = '#';
    if (y > 0 && v[x][y - 1] == '.')
      q.push({x, y - 1}), v[x][y - 1] = '#';
    if (x < n - 1 && v[x + 1][y] == '.')
      q.push({x + 1, y}), v[x + 1][y] = '#';
    if (y < m - 1 && v[x][y + 1] == '.')
      q.push({x, y + 1}), v[x][y + 1] = '#';
  }
}

void solve() {
  ll n, m, count = 0;
  cin >> n >> m;
  vector<vc> v(n, vc(m));
  cin >> v;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++)
      if (v[i][j] == '.')
        paint(v, i, j, n, m), count++;
  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}
