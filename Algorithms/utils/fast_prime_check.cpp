#include <iostream>

bool prime(int n) {
  if (n < 2)
    return false;
  for (int x = 2; x * x <= n; x++)
    if (n % x == 0)
      return false;
  return true;
}

int main() {
  using namespace std;
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    cout << (prime(m) ? "Prime" : "Not Prime") << endl;
  }
  return 0;
}
