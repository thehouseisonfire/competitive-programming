#include <stdio.h>

#define lld long long

lld solution(lld n) {
  if (n < 2)
    return 0;
  lld i = 1;
  for (; n > 0; i++) {
    n -= ((i * 3) - 1);
    printf("%lld ", i);
  }
  printf("yay\n");
  return i - 1;
}

int main() {
  lld n;
  scanf("%lld", &n);
  printf("%lld\n", solution(n));
  return 0;
}
