#include <algorithm>
#include <iostream>
#include <vector>

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
#define pi pair<int, int>

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

using namespace std;

int rsolution(int num, const vector<int> &choices, vector<int> &results) {

  if (num < 0)
    return 2000000000;
  if (num == 0)
    return 0;
  if (results[num] != -1)
    return results[num];
  int ret = 2000000000;
  for (const auto &pos : choices) {
    ret = min(ret, 1 + rsolution(num - pos, choices, results));
  }
  results[num] = ret;
  return ret;
}

int solution(int num, const vector<int> &choices, vector<int> &results) {

  results[0] = 0;
  for (int i = 1; i <= num; i++) {
    results[i] = 2000000000;
    for (const auto &pos : choices)
      if (pos <= i)
        results[i] = min(results[i], 1 + results[i - pos]);
  }
  return results[num];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &pos : v) {
      cin >> pos;
    }
    vector<int> r(m + 1);
    fill(r.begin(), r.end(), -1);
    cout << solution(m, v, r) << endl;
  }
  return 0;
}
