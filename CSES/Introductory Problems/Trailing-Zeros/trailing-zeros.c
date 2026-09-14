#include <stdio.h>

int solution(const int n) {
  int count = 0;
  int divider = 5;
  while (n >= divider) {
    count += n / divider;
    divider *= 5;
  }
  return count;
}
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", solution(n));
  return 0;
}
