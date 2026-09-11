#include <iostream>
#include <sstream>

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

bool isValidWord(const string &word) {
  int n = word.size();
  if (n == 0)
    return false;

  if (word[n - 1] == '.') {
    n--;
  }

  for (int i = 0; i < n; i++) {
    if (!isalpha(word[i])) {
      return false;
    }
  }
  return true;
}

int main() {
  string line;

  while (getline(cin, line)) {
    stringstream ss(line);
    string word;
    int totalLength = 0;
    int wordCount = 0;

    while (ss >> word) {
      if (isValidWord(word)) {
        int len = word.size();
        if (word[len - 1] == '.') {
          len--;
        }
        totalLength += len;
        wordCount++;
      }
    }

    int avgLength = (wordCount == 0) ? 0 : totalLength / wordCount;

    if (avgLength <= 3) {
      cout << 250 << endl;
    } else if (avgLength <= 5) {
      cout << 500 << endl;
    } else {
      cout << 1000 << endl;
    }
  }

  return 0;
}
