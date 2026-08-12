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

// int solution(const int num, const pi &choices, const vector<int> &holes,
//              vector<int> &results) {
//   if (num >= results.size())
//     return 0;
//   if (results[num] != -1)
//     return results[num];
//   // const auto low =
//   //     lower_bound(holes.cbegin(), holes.cend(), num) - holes.cbegin();
//   // const int ret =
//   //     min(choices.first + solution(num - choices.first, choices, results),
//   //         choices.second + solution(num - choices.second, choices,
//   results)); int ret = INF; for (const auto &pos : holes) {
//
//   }
//   results[num] = ret;
//   return ret;
// }

int solution(const int num, const pi &choices, const vector<int> &holes,
             vector<int> &results) {
  if (num >= *(holes.end() - 1))
    return 0;
  const auto upper = upper_bound(holes.cbegin(), holes.cend(), num);
  // DUO(num, upper);
  // cout << "num " << num << ": " << low << endl;
  if (upper == holes.cend())
    return 0;
  const int mini = min(
      choices.first + solution(*upper + choices.first, choices, holes, results),
      choices.second +
          solution(*upper + choices.second, choices, holes, results));
  results[num] = mini;
  cout << "upper " << *upper << ": " << mini << endl;
  return mini;

  // return min(choices.first + solution(num + choices.first, choices,
  // holes)); const auto low =
  //     lower_bound(holes.cbegin(), holes.cend(), num) - holes.cbegin();
  // const int ret =
  //     min(choices.first + solution(num - choices.first, choices, results),
  //         choices.second + solution(num - choices.second, choices,
  //         results));
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // const std::vector<int> data{1, 2, 4, 5, 5, 6};
  // for (int i = 0; i < 8; ++i) {
  //   // Search for first element x such that i ≤ x
  //   auto lower = upper_bound(data.begin(), data.end(), i);
  //   if (lower != data.end())
  //     DUO(i, *lower);
  // }
  // return 0;
  int n, c;
  pi choices;
  while (cin >> n >> c >> choices.first >> choices.second) {
    vector<int> holes(n);
    for (auto &pos : holes)
      cin >> pos;
    sort(holes.begin(), holes.end());
    vector<int> r(c);
    fill(r.begin(), r.end(), -1);

    // PI(choices);
    cout << solution(holes[0], choices, holes, r) << endl;
    for (int i = 0; i < c; i++) {
      cout << i << " ";
    }
    cout << endl;
    VEC(r)
    cout << endl << endl;
    // VEC(v);
  }
  return 0;
}
