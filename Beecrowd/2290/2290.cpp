#include <iostream>
#include <unordered_map>
#include <utility>

#define max 9223372036854775800

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  while (cin >> n) {
    if (!n)
      return 0;
    unordered_map<long long, bool> map;
    for (int i = 0; i < n; i++) {
      long long unsigned num;
      cin >> num;
      map[num] = !map[num];
    }
    pair<long long, long long> ans = make_pair(max, -max);
    for (auto pair : map) {
      if (pair.second) {
        if (ans.first == max)
          ans.first = pair.first;
        else {
          ans.second = pair.first;
          break;
        }
      }
    }
    if (ans.first > ans.second) {
      auto aux = ans.first;
      ans.first = ans.second;
      ans.second = aux;
    }
    cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}
