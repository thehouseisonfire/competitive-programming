#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
  int t, counter = 0;
  cin >> t;
  for (int J = 0; J < t; J++) {
    int n, v, a;
    map<pair<int, int>, bool> map;
    cin >> n;
    cin >> v >> a;
    int v1, v2, count = 0;
    for (int i = 0; i < a; i++) {
      cin >> v1 >> v2;
      if (!map[make_pair(v2, v1)]) {
        count += 2;
      }
      map[make_pair(v1, v2)] = true;
      map[make_pair(v2, v1)] = true;
    }
    counter++;
    cout << count << endl;
  }
}
