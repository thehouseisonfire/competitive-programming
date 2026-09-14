#include <bits/stdc++.h>

using namespace std;

void printbits(const short unsigned x, const char n_bits) {
  for (int i = n_bits; i; i--)
    cout << char('0' + ((x >> (i - 1)) & 1));
}

int main() {
  int n;
  cin >> n;
  for (unsigned i = 0; i < (2 << (n - 1)); i++) {
    printbits(i ^ (i >> 1), n);
    cout << endl;
  }
  return 0;
}
