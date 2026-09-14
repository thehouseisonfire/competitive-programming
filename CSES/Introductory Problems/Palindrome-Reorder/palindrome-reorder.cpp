#include <iostream>

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  str.reserve(1000);
  cin >> str;
  int letters[26] = {0};
  for (const auto &c : str)
    letters[c - 'A']++;
  int odds = 0;
  for (const auto &l : letters)
    if (l % 2)
      odds++;
  if (odds > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  int start = 0;
  int end = str.length() - 1;
  for (int i = 0; i < 26; i++) {
    if (letters[i] % 2) {
      str[str.length() >> 1] = i + 'A';
      letters[i]--;
    }
    while (letters[i] > 0) {
      str[start] = i + 'A';
      str[end] = i + 'A';
      start++;
      end--;
      letters[i] -= 2;
    }
  }
  cout << str << endl;
  return 0;
}
