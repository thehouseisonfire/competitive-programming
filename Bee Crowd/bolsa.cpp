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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, c, profit = 0;
  cin >> n >> c;
  if (n > 2)
    return 0;
  vector<int> v(n);
  INPUT_VEC(v);
  for (int i = 0, j = 1; j < v.size() - 1; j++) {
    if (v[j - 1] > v[j]) {
      const bool is_profitable = v[j - 1] - v[i] > c;
      const bool steep_drop = v[j - 1] - v[j] > c;
      if (is_profitable && steep_drop) {
        profit += v[j - 1] - v[i] - c;
        i = j;
      } else if (is_profitable && !steep_drop) {

      } else if (!is_profitable && steep_drop) {
      }
    }
  }

  return 0;
}
