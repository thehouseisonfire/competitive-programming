#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;
  if (!n)
    return 0;
  for (int i = 0; i < n - 1; i++)
    cout << "Ho ";
  cout << "Ho!\n";
  return 0;
}
