#include <algorithm>
#include <climits>
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

int solve(const vector<int> &v, const int target, const ll needed) {

  ll count = 0;
  ll used = 0;
  ll i = 0;
  ll j = v.size() - 1;

  while (j >= 0 && v[j] > target)
    j--;

  while (j >= 0 && v[j] == target && count < needed) {
    j--;
    count++;
    used++;
  }
  while (i < j && count < needed) {
    ll curr = v[i] + v[j];
    if (curr == target)
      count++, used += 2, i++, j--;
    else if (curr < target)
      i++;
    else
      j--;
  }

  return count == needed ? used : INT_MAX;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, q;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    cin >> q;
    int k;
    cin >> k;

    vector<int> v(k);
    INPUT_VEC(v);

    sort(v.begin(), v.end());

    int count = INT_MAX, count2 = INT_MAX;

    if ((m * 100) % q == 0)
      count = solve(v, n, (m * 100) / q);
    if ((n * 100) % q == 0)
      count2 = solve(v, m, (n * 100) / q);

    const ll res = min(count, count2);
    if (res == INT_MAX) {
      cout << "impossivel" << endl;
    } else
      cout << res << endl;
  }

  return 0;
}
