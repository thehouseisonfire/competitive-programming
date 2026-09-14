#include <stdio.h>

#define u64 unsigned long long

void solution(int n) {

  u64 sum = ((u64)n * n + n) / 2;
  if (sum % 2) {
    printf("NO\n");
    return;
  }

  u64 count = 1;
  sum >>= 1;
  u64 aux_sum = sum;

  printf("YES\n");
  for (u64 i = n; aux_sum > i; i--) {
    aux_sum -= i;
    count++;
  }
  printf("%llu\n", count);
  for (u64 i = n; sum > i; i--) {
    sum -= i;
    printf("%llu ", i);
  }
  printf("%llu\n", sum);
  printf("%llu\n", n - count);
  for (u64 i = 1; i < n + 2 - count; i++) {
    if (i != sum)
      printf("%llu ", i);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  u64 n;
  scanf("%llu", &n);
  solution(n);
  return 0;
}
