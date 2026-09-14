// https://codeforces.com/gym/102219/problem/J

#include <algorithm>
#include <iostream>
#include <string>
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

string solution(const vector<string> &v) {
  string str = "ABCDE";
  vector<string> res;

  while (next_permutation(str.begin(), str.end())) {
    bool flag = true;

    for (const auto &s : v) {

      const auto a = s[0];
      const auto c = s[1];
      const auto b = s[2];

      int i, j;
      for (int k = 0; k < 5; k++) {
        if (str[k] == a)
          i = k;
        if (str[k] == b)
          j = k;
      }

      if (c == '>')
        swap(i, j);

      if (i > j) {
        flag = false;
        break;
      }
    }

    if (flag)
      res.push_back(str);
  }

  if (res.empty() || res.size() > 1)
    return "impossible";

  return res[0];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<string> v(5);
  INPUT_VEC(v);
  cout << solution(v) << endl;

  return 0;
}
