#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
#define ll long long
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
ll factorial(const ll n) {
  if (n < 3)
    return n;
  vector<ll> results(n + 1);
  results[2] = 2;
  for (ll i = 3; i <= n; i++)
    results[i] = i * results[i - 1];
  return results[n];
}

ll formula(const string &str) {
  ll alphabet[26] = {0};
  for (const char c : str) {
    alphabet[c - 'A']++;
  }
  ll result = factorial(str.length()) % MOD;
  cout << result << endl;
  ll divide = 1;
  for (ll i = 0; i < 26; i++) {
    if (alphabet[i] > 1)
      divide *= factorial(alphabet[i]) % MOD;
  }
  return result / divide;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  str.reserve(69);
  cin >> str;
  ll ammount = formula(str);
  cout << ammount << endl;
  return 0;
}
