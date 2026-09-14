// https://codeforces.com/gym/106073/problem/M

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

ll n, k;
bool check(const ll m, const vector<ll> &v) {
  ll l = -1, r = -1;
  for (ll i = 0; i < n; i++) {
    if (v[i] < m) {
      if (l == -1)
        l = i;
      r = i;
    }
  }
  if (l == -1)
    return true;
  if (r - l + 1 > k)
    return false;

  ll minimum = INF;
  for (ll j = l; j <= r; j++) {
    ll pos = j + k - m + v[j];
    minimum = min(minimum, pos);
  }
  return r <= minimum;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  vector<ll> v(n);
  INPUT_VEC(v)

  ll minimum = INF, maximum = -INF;
  for (const auto &pos : v)
    minimum = min(minimum, pos), maximum = max(maximum, pos);

  maximum += k;

  while (minimum < maximum) {
    ll mid = (minimum + maximum + 1) >> 1;
    if (check(mid, v))
      minimum = mid;
    else
      maximum = mid - 1;
  }

  cout << minimum << endl;
  return 0;
}
