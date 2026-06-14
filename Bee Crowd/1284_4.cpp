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

int lcs(string &S1, string &S2, int m, int n, vector<vector<int>> &memo) {

  // Base Case
  if (m == 0 || n == 0)
    return 0;

  // Already exists in the memo table
  if (memo[m][n] != -1)
    return memo[m][n];

  // Match
  if (S1[m - 1] == S2[n - 1])
    return memo[m][n] = 1 + lcs(S1, S2, m - 1, n - 1, memo);

  // Do not match
  return memo[m][n] =
             max(lcs(S1, S2, m, n - 1, memo), lcs(S1, S2, m - 1, n, memo));
}

string traverse(const vector<string> &grid, int startX, int startY,
                const string &directions) {
  string result;
  int x = startX - 1, y = startY - 1;
  result += grid[x][y];

  for (char direction : directions) {
    switch (direction) {
    case 'N':
      x--;
      break;
    case 'S':
      x++;
      break;
    case 'E':
      y++;
      break;
    case 'W':
      y--;
      break;
    }
    result += grid[x][y];
  }

  return result;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int m, o;
    cin >> m >> o;
    vector<string> v(m);
    INPUT_VEC(v)

    int a, b, c, d, e, f;
    string s, s2;
    cin >> a >> b >> c >> s;
    cin >> d >> e >> f >> s2;

    string p1 = traverse(v, b, c, s);
    string p2 = traverse(v, e, f, s2);

    int x = p1.length();
    int z = p2.length();

    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    int lcs_length = lcs(p1, p2, x, z, memo);
    int deletionsA = p1.size() - lcs_length;
    int deletionsB = p2.size() - lcs_length;

    cout << "Case " << i << ": " << deletionsA << " " << deletionsB << endl;
  }

  return 0;
}
