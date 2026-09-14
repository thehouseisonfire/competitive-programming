#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n < 4) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  for (int i = 2; i <= n; i += 2)
    cout << i << " ";
  for (int i = 1; i < n - 1; i += 2)
    cout << i << " ";
  if (!(n % 2))
    n--;
  cout << n << endl;

  return 0;
}
