#include <stdio.h>

// the number of coins (x+y) needs to be a multiple of 3
// x needs to be at least half of y and vie versa
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for (; 0 < n; n--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (!((x + y) % 3) && x - y <= y && y - x <= x)
      puts("YES\n");
    else
      puts("NO\n");
  }
  return 0;
}
