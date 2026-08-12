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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int solution(const pi params, const vector<pi> &choices,
             vector<vector<int>> &results) {
  const auto [space, index] = params;
  if (space < 0)
    return -INF;
  if (space == 0)
    return 0;
  if (index < 0)
    return 0;
  if (results[space][index])
    return results[space][index];

  const auto &[value, cost] = choices[index];
  int best = max(solution({space, index - 1}, choices, results),
                 value + solution({space - cost, index - 1}, choices, results));
  results[space][index] = best;
  return best;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pi> v(n);
  vector<vector<int>> res(m + 1, vector<int>(n));
  INPUT_DUO_VEC(v);
  cout << solution({m, n - 1}, v, res) << endl;
  // for (const auto &r : res) {
  //   PRINT_VEC(r);
  // }

  return 0;
}
