#include <stdio.h>

int main(int argc, char *argv[]) {
  int n, prev;
  long long count = 0;
  scanf("%d", &n);
  scanf("%d", &prev);
  for (; 1 < n; n--) {
    int aux;
    scanf("%d", &aux);
    if (aux < prev)
      count += prev - aux;
    else
      prev = aux;
  }
  printf("%lld\n", count);
  return 0;
}
