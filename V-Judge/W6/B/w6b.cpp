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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<ll> v(n + 1);
  vector<pll> dist(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> dist[i].first >> dist[i].second;

  for (int i = 1; i < n; i++) {
    const auto [x, y] = dist[i];
    const auto [nx, ny] = dist[i + 1];
    if (x == nx) {
      ll diff = ny - y;
      if (diff < 0)
        diff = -diff;
      v[i] = diff;
    } else {
      ll diff = nx - x;
      if (diff < 0)
        diff = -diff;
      v[i] = diff;
    }
  }

  vector<ll> t(n + 1);
  for (int i = 1; i < n; i++) {
    t[i + 1] = v[i] - t[i];
  }

  ll l = -1e18, r = 1e18;

  for (int i = 1; i <= n - 1; i++) {
    if (i % 2) {
      ll lower = 1 - t[i];
      ll upper = v[i] - 1 - t[i];
      l = max(l, lower);
      r = min(r, upper);
    } else {
      ll lower = t[i] - v[i] + 1;
      ll upper = t[i] - 1;
      l = max(l, lower);
      r = min(r, upper);
    }
  }

  if (n % 2) {
    ll lower = 1 - t[n];
    l = max(l, lower);
  } else {
    ll upper = t[n] - 1;
    r = min(r, upper);
  }

  cout << (l <= r ? r : -1) << endl;

  return 0;
}
