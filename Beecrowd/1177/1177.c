#include <stdio.h>

void solution(int n) {
  for (short unsigned i = 0; i < 1000; i++)
    printf("N[%u] = %u\n", i, i % n);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  solution(n);
  return 0;
}
