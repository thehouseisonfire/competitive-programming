#include <iostream>
#include <string>
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

vector<pll> v;

ll dfs(const ll start, const ll n, ll current, vector<ll> &visited) {

  if (visited[start]) {
    return (visited[start] == current);
  }

  visited[start] = current;
  // DBG(start);
  // DBG(current);
  auto [next, mark] = v[start];
  // DBG(next);
  // DBG(mark);

  if (current == 1 && next == 1)
    current = 2;
  if (current == 2 && next == 1)
    current = 1;
  if (current == 1 && next == 2)
    current = 1;
  if (current == 2 && next == 2)
    current = 2;

  return 1 + dfs(next, n, current, visited);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);
  ll n;
  while (cin >> n && n) {
    cin.ignore();
    v = vector<pll>(n);
    for (ll i = 0; i < n; i++) {
      string m;
      getline(cin, m);
      ll tru = m.find("false.");
      ll u = m[9] - '0' - 1;
      v[i] = {u, (tru == string::npos) + 1};
    }
    // PRINT_DUO_VEC(v);
    ll res = 0;
    for (ll i = 0; i < n; i++) {
      auto [node, val] = v[i];
      // DBG(val);
      vector<ll> visited(n, 0);
      visited[i] = val;
      // PRINT_VEC(visited);

      res = max(res, dfs(node, n, 2, visited));
    }
    if (res == 0)
      cout << "Inconsistent" << endl;
    else
      cout << res << endl;
  }

  return 0;
}
