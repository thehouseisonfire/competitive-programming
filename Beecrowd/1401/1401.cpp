#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  string str;
  str.reserve(100);
  int n;
  cin >> n;
  while (n--) {
    cin >> str;
    sort(str.begin(), str.end());
    cout << str << endl;
    while (next_permutation(str.begin(), str.end()))
      cout << str << endl;
    cout << endl;
  }
  return 0;
}
