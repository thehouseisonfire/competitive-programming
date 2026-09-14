#include <stdio.h>

void printbits(const short unsigned x, const char n_bits) {
  for (int i = n_bits; i; i--)
    putchar('0' + ((x >> (i - 1)) & 1));
}

int main() {
  unsigned char n;
  scanf("%hhu", &n);
  for (unsigned i = 0; i < (2 << (n - 1)); i++) {
    printbits(i ^ (i >> 1), n);
    putchar('\n');
  }
  return 0;
}
