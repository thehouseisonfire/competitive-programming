#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m)
      return 0;
    unordered_map<int, int> map;
    while (n--) {
      for (int i = 0; i < m; i++) {
        int aux;
        cin >> aux;
        map[aux]++;
      }
    }
    int max = 0;
    for (const auto &pos : map) {
      if (pos.second > max)
        max = pos.second;
    }
    int sec_max = 0;
    for (const auto &pos : map) {
      if (pos.second != max && pos.second > sec_max)
        sec_max = pos.second;
    }
    set<int> s;
    for (const auto &pos : map) {
      if (pos.second == sec_max)
        s.insert(pos.first);
    }
    for (const auto &pos : s) {
      cout << pos << " ";
    }
    cout << endl;
  }
  return 0;
}
