#include <stdio.h>

const int MOD = (int)1e9 + 7;

int main(int argc, char *argv[]) {
  int n;
  int ans = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    ans = (ans << 1) % MOD;
  printf("%d\n", ans);
  return 0;
}
