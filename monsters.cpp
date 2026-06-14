#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define rb pop_back
#define F(x) fixed << setprecision(1) << (x)
#define pv(x)                                                                  \
  for (auto &i : x)                                                            \
    cout << i << " ";                                                          \
  cout << endl;
#define rv(x)                                                                  \
  for (auto &i : x)                                                            \
    cin >> i;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
using namespace std;

// for unordered map int
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

int main(int argc, char *argv[]) {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  cout << 1 << endl;

  vector<vector<pair<char, char>>> a(n, vector<pair<char, char>>(m));
  vector<pair<int, int>> monsters;
  int si, sj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j].first;
      a[i][j].second = a[i][j].first;
      if (a[i][j].first == 'A') {
        si = i;
        sj = j;
      }
      if (a[i][j].first == 'M') {
        monsters.pb({i, j});
      }
    }
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cout << a[i][j].first << " ";
    }
    cout << endl;
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cout << a[i][j].second << " ";
    }
    cout << endl;
  }

  queue<pair<pair<ll, ll>, ll>> q;
  q.push({{si, sj}, 0});
  a[si][sj].second = 0;
  while (!q.empty()) {
    auto [pr, dist] = q.front();
    q.pop();
    auto [ni, nj] = pr;
    a[ni][nj].second = dist + 1;
    if (ni > 0 && a[ni + 1][nj].second != '#' && a[ni + 1][nj].second != 'E')
      q.push({{ni + 1, nj}, dist + 1});
    if (nj > 0 && a[ni][nj + 1].second != '#' && a[ni + 1][nj].second != 'E')
      q.push({{ni, nj + 1}, dist + 1});
    if (ni < n - 1 && a[ni - 1][nj].second != '#' &&
        a[ni + 1][nj].second != 'E')
      q.push({{ni - 1, nj}, dist + 1});
    if (ni < m - 1 && a[ni][nj - 1].second != '#' &&
        a[ni + 1][nj].second != 'E')
      q.push({{ni, nj - 1}, dist + 1});
  }

  for (ll i = 0; i < monsters.size(); i++) {
    q.push({monsters[i], 0});
    const auto [x, y] = monsters[i];
    a[x][y].first = 0;
  }
  while (!q.empty()) {
    auto [pr, dist] = q.front();
    q.pop();
    auto [ni, nj] = pr;
    a[ni][nj].second = dist + 1;
    if (ni > 0 && a[ni + 1][nj].second != '#' && a[ni + 1][nj].second != 'E')
      q.push({{ni + 1, nj}, dist + 1});
    if (nj > 0 && a[ni][nj + 1].second != '#' && a[ni + 1][nj].second != 'E')
      q.push({{ni, nj + 1}, dist + 1});
    if (ni < n - 1 && a[ni - 1][nj].second != '#' &&
        a[ni + 1][nj].second != 'E')
      q.push({{ni - 1, nj}, dist + 1});
    if (ni < m - 1 && a[ni][nj - 1].second != '#' &&
        a[ni + 1][nj].second != 'E')
      q.push({{ni, nj - 1}, dist + 1});
  }

  vector<pair<ll, ll>> saidas;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if ((i != 0 && j != 0) || (i != n && j != m) || a[i][j].first != '.')
        continue;
      saidas.push_back({i, j});
    }
  }

  pair<ll, ll> res = {-1, -1};
  for (const auto [i, j] : saidas) {
    if (a[i][j].second < a[i][j].first) {
      res = {0, 0};
      break;
    }
  }
  if (res.first == -1) {
    cout << "se fudeu" << endl;
    return 0;
  }

  map<pair<ll, ll>, pair<ll, ll>> ansc;

  q.push({{si, sj}, 0});
  a[si][sj].second = 0;
  while (!q.empty()) {
    auto [pr, dist] = q.front();
    q.pop();
    auto [ni, nj] = pr;
    if (ni > 0 && a[ni + 1][nj].second != '#' && a[ni + 1][nj].second != 'E') {
      q.push({{ni + 1, nj}, dist + 1});
      ansc[{ni + 1, nj}] = {ni, nj};
    }
    if (nj > 0 && a[ni][nj + 1].second != '#' && a[ni + 1][nj].second != 'E') {
      q.push({{ni, nj + 1}, dist + 1});
      ansc[{ni, nj + 1}] = {ni, nj};
    }
    if (ni < n - 1 && a[ni - 1][nj].second != '#' &&
        a[ni + 1][nj].second != 'E') {
      q.push({{ni - 1, nj}, dist + 1});
      ansc[{ni - 1, nj}] = {ni, nj};
    }
    if (ni < m - 1 && a[ni][nj - 1].second != '#' &&
        a[ni + 1][nj].second != 'E') {
      q.push({{ni, nj - 1}, dist + 1});
      ansc[{ni, nj - 1}] = {ni, nj};
    }
  }
  vector<pair<int, int>> path;
  int c = res.first, v = res.second;
  path.pb({c, v});
  // cout << c << " " << v << endl;
  while (c != si || v != sj) {
    path.pb({ansc[{c, v}]});
    tie(c, v) = ansc[{c, v}];
    // cout << c << " " << v << endl;
  }

  /*for(auto &i : path){
      cout << i.first << " " << i.second << endl;
  }*/

  // path.pb({si, sj});
  reverse(all(path));
  cout << "YES" << endl;
  cout << path.size() - 1 << endl;

  for (int i = 0; i < path.size() - 1; i++) {
    if (path[i].first > path[i + 1].first)
      cout << "U";
    else if (path[i].first < path[i + 1].first)
      cout << "D";
    else if (path[i].second > path[i + 1].second)
      cout << "L";
    else
      cout << "R";
  }
  cout << endl;

  return 0;
}
