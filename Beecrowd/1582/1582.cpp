#include <iostream>
#include <numeric>
#include <string>

int main(int argc, char *argv[]) {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, y, z;
  while (cin >> x >> y >> z) {
    string res = "tripla";
    if (y > z)
      swap(y, z);
    if (x > z)
      swap(x, z);
    if (y > z)
      swap(y, z);
    if (x * x + y * y == z * z) {
      res += " pitagorica";
      if (gcd(x, y) == 1 && gcd(y, z) == 1)
        res += " primitiva";
    }
    cout << res << endl;
  }
  return 0;
}
