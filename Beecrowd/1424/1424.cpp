#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
#define pi pair<int, int>

int main() {
  int n, m;
  map<pi, int> indexes;
  while (cin >> n >> m) {
    unordered_map<int, int> instances;
    for (int i = 1; i <= n; i++) {
      int aux;
      cin >> aux;
      instances[aux]++;
      indexes[{instances[aux], aux}] = i;
    }
    while (m--) {
      int g, h;
      cin >> g >> h;
      cout << indexes[{g, h}] << endl;
    }
    indexes.clear();
  }
  return 0;
}
