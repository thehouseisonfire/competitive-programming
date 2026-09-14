#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main(int argc, char *argv[]) {
  ll t;
  cin >> t;
  vector<pair<int, int>> vec(t);
  for (auto &pos : vec) {
    int f, d;
    cin >> f >> d;
    pos = {f, d};
  }
  sort(vec.begin(), vec.end());
  ll timer = 0, reward = 0;
  for (auto &p : vec) {
    timer += p.first;
    reward += p.second - timer;
  }
  cout << reward << endl;
  return 0;
}
