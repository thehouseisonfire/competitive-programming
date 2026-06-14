#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int
#define pi pair<int, int>

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

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

int solution(const int num, const vector<pi> &choices, vector<int> &results) {
  if (num < 0)
    return -200000000;
  if (num == 0)
    return 0;
  if (results[num] != -1)
    return results[num];
  int ret = 0;
  for (const auto &pos : choices) {
    if (pos.first > num)
      break;
    const int aux = pos.second + solution(num - pos.first, choices, results);
    ret = max(ret, aux);
  }
  results[num] = ret;
  return ret;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, counter = 1;
  while (cin >> n >> m) {
    if (!n && !m)
      return 0;
    vector<pi> v(n);
    for (auto &pos : v) {
      cin >> pos.first >> pos.second;
    }
    sort(v.begin(), v.end()); // PERF: COULD JUST SAVE THE LOWEST AND CHECK IT
                              // FIRST IN THE SOLUTION (the 'if' in the choices
                              // loop breaks if we don't)
    vector<int> r(m + 1);
    fill(r.begin(), r.end(), -1);
    cout << "Instancia " << counter << endl
         << solution(m, v, r) << endl
         << endl;
    counter++;
    // PI(v[0]);
    // DUO(v[0].first, v[1].second);
    // VEC(r);
  }
}
