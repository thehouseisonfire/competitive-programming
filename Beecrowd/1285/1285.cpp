#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, m;
  while (cin >> n >> m) {
    int count = 0;
    for (int i = n; i <= m; i++) {
      string s = to_string(i);
      bool letters[10] = {0};
      bool flag = true;
      for (const auto &c : s) {
        if (letters[c - '0']) {
          flag = false;
          break;
        } else {
          letters[c - '0'] = true;
        }
      }
      if (flag)
        count++;
    }
    cout << count << endl;
  }
  return 0;
}
