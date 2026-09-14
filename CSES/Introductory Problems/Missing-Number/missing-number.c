#include <stdio.h>

int main(int argc, char *argv[]) {
  long n, sum;
  scanf("%ld\n", &n);
  sum = (n * n + n) / 2;
  for (int i = 0; i < n - 1; i++) {
    int diff;
    scanf("%d", &diff);
    sum -= diff;
  }
  printf("%ld", sum);
  return 0;
}
