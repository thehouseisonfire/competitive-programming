#include <iostream>
int main() {
  using namespace std;
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string buf;
  while (cin >> buf) {
    int count = 0;
    for (char i : buf) {
      if (i == '(')
        count++;
      else if (i == ')') {
        count--;
        if (count < 0)
          break;
      }
    }
    !count ? cout << "correct\n" : cout << "incorrect\n";
  }
  return 0;
}
