#include <stdio.h>

int main(int argc, char *argv[]) {
  char c;
  char prev = ' ';
  int t_count = 1;
  int s_count = 1;
  while (scanf("%c", &c) != EOF) {
    if (c == prev) {
      s_count++;
      if (s_count > t_count)
        t_count = s_count;
    } else {
      prev = c;
      s_count = 1;
    }
  }
  printf("%d\n", t_count);
  return 0;
}
