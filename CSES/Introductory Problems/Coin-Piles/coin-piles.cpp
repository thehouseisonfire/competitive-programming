#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (; 0 < n; n--) {
    int x, y;
    cin >> x >> y;
    if (!((x + y) % 3) && x - y <= y && y - x <= x)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
