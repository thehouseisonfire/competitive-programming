#include <iostream>

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

const int SIZE = 6;
int mtx[SIZE][SIZE];

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      mtx[i][j] = 1;
    }
  }

  while (n--) {

    bool flag = false;
    for (int i = 1; i < SIZE - 1; i++)
      for (int j = 1; j < SIZE - 1; j++) {
        cin >> mtx[i][j];
        if (mtx[i][j] == 2048) {
          flag = true;
        }
      }
    if (flag) {
      cout << "NONE" << endl;
      continue;
    }

    bool res[4] = {0};

    for (int i = 1; i < SIZE - 1; i++)
      for (int j = 1; j < SIZE - 1; j++) {

        const int sqr = mtx[i][j];
        const int left = mtx[i][j - 1];
        const int up = mtx[i - 1][j];
        const int down = mtx[i + 1][j];
        const int right = mtx[i][j + 1];

        if (!sqr)
          continue;
        res[0] = (res[0] || !down || sqr == down);
        res[1] = (res[1] || !left || sqr == left);
        res[2] = (res[2] || !up || sqr == up);
        res[3] = (res[3] || !right || sqr == right);
      }

    string str = "";
    if (res[0])
      str += "DOWN";
    if (res[1])
      str += !str.length() ? "LEFT" : " LEFT";
    if (res[3])
      str += !str.length() ? "RIGHT" : " RIGHT";
    if (res[2])
      str += !str.length() ? "UP" : " UP";

    if (!str.length())
      str = "NONE";

    cout << str << endl;
  }

  return 0;
}
