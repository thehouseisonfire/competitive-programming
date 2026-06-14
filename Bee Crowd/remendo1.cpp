#include <algorithm>
#include <iostream>
#include <vector>

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
#define pi pair<int, int>

// #define ASCII_NUMBER_OFFSET 48
// #define ASCII_UPPERCASE_OFFSET 65
// #define ASCII_LOWERCASE_OFFSET 97
#define INF 2147483647
#define ASCII_NUMBER_OFFSET '0'
#define ASCII_UPPERCASE_OFFSET 'A'
#define ASCII_LOWERCASE_OFFSET 'a'

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define PI(x) cout << x.first << " " << x.second << endl
#define DUO(x, y) cout << x << " " << y << endl
#define VEC(v)                                                                 \
  for (const auto &pos : v) {                                                  \
    cout << pos << " ";                                                        \
  }                                                                            \
  cout << endl;

using namespace std;

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int solution(const int num, const pi &choices, vector<int> &results,
             const vector<int> &holes) {
  if (num < 0)
    return 200000000;
  if (num == 0)
    return 0;
  if (results[num] != -1)
    return results[num];
  // const int ret =
  //     min(choices.first + solution(num - choices.first, choices, results),
  //         choices.second + solution(num - choices.second, choices, results));
  int ret = INF;
  for (const auto &pos : holes) {
  }
  results[num] = ret;
  return ret;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  pi choices;
  while (cin >> n >> c >> choices.first >> choices.second) {
    vector<int> v(n);
    for (auto &pos : v)
      cin >> pos;
    pi target = {v[0], v[0]};
    for (const auto &pos : v) {
      if (target.first > pos)
        target.first = pos;
      if (target.second < pos)
        target.second = pos;
    }
    vector<int> r(c);
    fill(r.begin(), r.end(), -1);

    cout << target.second - target.first << endl;
    PI(choices);
    cout << solution(target.second - target.first, choices, r) << endl;
    // VEC(v);
  }
  return 0;
}
