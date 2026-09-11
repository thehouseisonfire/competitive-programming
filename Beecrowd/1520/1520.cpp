#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    vector<int> v;
    v.reserve(n << 2);
    while (n--) {
      int a, b;
      cin >> a >> b;
      for (int i = a; i <= b; i++) {
        v.push_back(i);
      }
    }
    sort(v.begin(), v.end());
    int a, b = -1, e = -1;
    cin >> a;
    // for (const auto &pos : v)
    //   cout << pos << " ";
    // cout << endl;
    // continue;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == a)
        b = i;
      else
        continue;
      while (v[i] == a)
        i++;
      e = i - 1;
      break;
    }
    if (b == -1)
      cout << a << " not found\n";
    else
      cout << a << " found from " << b << " to " << e << endl;
  }
  return 0;
}
