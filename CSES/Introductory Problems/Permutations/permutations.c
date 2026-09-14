#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  if (n < 4) {
    printf("NO SOLUTION\n");
    return 0;
  }
  for (int i = 2; i <= n; i += 2) {
    printf("%d ", i);
  }
  for (int i = 1; i < n - 1; i += 2) {
    printf("%d ", i);
  }
  if (!(n % 2))
    n--;
  printf("%d\n", n);

  return 0;
}
