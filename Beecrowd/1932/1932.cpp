#include <iostream>
#include <vector>

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
#define i64 long long
#define u64 long long unsigned
#define pi pair<int, int>

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

int maxn = 2 * 1e5 + 100;
int n, c;
vector<int> v(maxn);
vector<vector<int>> dp(maxn, vector<int>(2, -INF));

int solution(int d, bool can_buy) {

  dp[n][0] = dp[n][1] = 0;

  for (int d = n - 1; d >= 0; d--) {
    dp[d][1] = max(dp[d + 1][1], dp[d + 1][0] - c - v[d]);
    dp[d][0] = max(dp[d + 1][0], dp[d + 1][1] + v[d]);
  }
  return dp[0][1];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << solution(0, true) << endl;

  return 0;
}
