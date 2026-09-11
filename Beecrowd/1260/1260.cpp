#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  cin.ignore();
  cin.ignore();
  cout << fixed;
  while (t--) {
    int count = 0;
    string str;
    str.reserve(30);
    map<string, int> map;
    while (getline(cin, str)) {
      if (str == "" || str == "\n")
        break;
      map[str]++;
      count++;
    }
    for (auto p : map) {
      cout << setprecision(4) << p.first << " "
           << ((float)p.second / count) * 100 << endl;
    }
    if (t != 0)
      cout << endl;
  }
  return 0;
}
