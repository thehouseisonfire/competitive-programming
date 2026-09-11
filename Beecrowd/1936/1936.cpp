#include <iostream>

using namespace std;

int fatorial(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  return n * fatorial(n - 1);
}

int main(int argc, char *argv[]) {
  int n = 0, number;
  cin >> number;
  while (number > 0) {
    int fac = 1;
    while (fatorial(fac) <= number) {
      fac++;
      // cout << fac << endl;
    }
    fac--;
    number -= fatorial(fac);
    // cout << fac << "!, number = " << number << endl;
    n++;
  }
  cout << n << endl;
  return 0;
}
