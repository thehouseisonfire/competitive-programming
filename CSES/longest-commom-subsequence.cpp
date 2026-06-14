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

const int MAX = 1005;

int n, m;

vector<int> mtx[MAX][MAX];

void start() {

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      mtx[i][j] = vector<int>();
    }
  }
}

// void solution(const vector<int> &v1, const vector<int> &v2,
//               vector<vector<vector<int>>> &mtx) {
void solution(const vector<int> &v1, const vector<int> &v2) {

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        continue;

      const auto a = v1[i - 1], b = v2[j - 1];
      if (a == b) {
        auto curr = mtx[i - 1][j - 1];
        curr.push_back(a);
        mtx[i][j] = curr;
        continue;
      }
      const auto p1 = mtx[i - 1][j], p2 = mtx[i][j - 1];
      mtx[i][j] = p1.size() > p2.size() ? p1 : p2;
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  start();
  // vector<vector<vector<int>>> mtx(n + 1,
  //                                 vector<vector<int>>(m + 1, vector<int>()));

  vector<int> v1(n);
  vector<int> v2(m);
  INPUT_VEC(v1);
  INPUT_VEC(v2);

  solution(v1, v2);

  cout << mtx[n][m].size() << endl;
  PRINT_VEC(mtx[n][m])

  // for (auto &v : mtx) {
  //   for (auto &o : v) {
  //     cout << o.size() << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
