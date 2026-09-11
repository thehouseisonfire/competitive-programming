#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define pii pair<double, pair<int, int>>

int main() {

  int n, m;
  cin >> n >> m;
  vector<pii> v(n);
  for (auto &pos : v)
    cin >> pos.second.first;
  for (auto &pos : v)
    cin >> pos.second.second;
  for (auto &pos : v)
    pos.first = (float)pos.second.first / pos.second.second;
  sort(v.begin(), v.end(), greater<pii>());
  int count = 0;
  for (const auto &p : v) {
    if (p.second.second > m) {
      count += p.first * m;
      break;
    }
    count += p.second.first;
    m -= p.second.second;
  }
  cout << (int)(-0.5 + sqrt(0.25 + 2 * count)) << endl;

  return 0;
}
