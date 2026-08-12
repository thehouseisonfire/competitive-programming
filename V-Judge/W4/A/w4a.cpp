#include <algorithm>
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
const int MAXN = 100005;

bool comp(const pll &a, const pll &b) { return a.second < b.second; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  const ll size = 2 * n;
  vector<ll> v(size);
  INPUT_VEC(v);

  vector<ll> temp(n + 1, -1);
  vector<pll> windows;
  for (ll i = 0; i < size; i++) {
    const ll pos = v[i];
    if (temp[pos] == -1)
      temp[pos] = i;
    else
      windows.push_back({temp[pos], i});
  }

  sort(windows.begin(), windows.end(), comp);

  const ll m = windows.size();
  vector<ll> dp(m + 1, 0);
  vector<ll> costs(m + 1, 0);
  vector<ll> ends(m);
  for (ll k = 0; k < m; ++k)
    ends[k] = windows[k].second;

  for (ll i = 0; i < m; i++) {

    const auto [l, r] = windows[i];

    const ll j =
        upper_bound(ends.begin(), ends.begin() + i, l - 1) - ends.begin() - 1;

    const ll points = 1 + (j >= 0 ? dp[j + 1] : 0);
    const ll cost = r - l + (j >= 0 ? costs[j + 1] : 0);

    if (points > dp[i]) {
      dp[i + 1] = points;
      costs[i + 1] = cost;
    } else if (points == dp[i]) {
      dp[i + 1] = points;
      costs[i + 1] = min(costs[i], cost);
    } else {
      dp[i + 1] = dp[i];
      costs[i + 1] = costs[i];
    }
  }

  DUO(dp[m], costs[m]);

  return 0;
}
