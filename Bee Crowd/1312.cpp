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

const int MAX = 1000;

int mtx[MAX][MAX];
bool marked[MAX][MAX];

void mark(int i, int j) {
  marked[i][j] = true;
  if (j != 0 && i != 0)
    mark(i - 1, j - 1);
  if (i != j)
    mark(i - 1, j);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {

    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++) {
        cin >> mtx[i][j];
        marked[i][j] = false;
      }
    for (int i = 1; i < n; i++)
      for (int j = 0; j <= i; j++) {
        const int left = j == 0 ? 0 : mtx[i - 1][j - 1];
        const int right = i == j ? 0 : mtx[i - 1][j];
        mtx[i][j] = left + right; // prefix of balls atop + itself
      }
    ll sum = 0;
    for (int i = n; i >= 0; i--)
      for (int j = i; j >= 0; j--) {
        bool left_exists = !(j == 0 || i == 0);
        bool right_exists = (j == i);
        int left, right;
        if (left_exists) {
        }
        int left = left_exists ? 0 : mtx[i - 1][j - 1];
        const int right = right_exists ? 0 : mtx[i - 1][j];
        const int curr = mtx[i][j] - left - right;
        if (!marked[i - 1][j - 1] && left_exists &&
            (left > 0 || left + curr + right > 0)) {
          mark(i - 1, j - 1);
        }
        sum += left;
        if (right > 0 || left + curr + right > 0)
          sum += right;
        if ()
          sum += right;
      }
  }

  return 0;
}
