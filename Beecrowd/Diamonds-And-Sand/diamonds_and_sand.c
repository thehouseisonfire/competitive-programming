#include <stdio.h>
#include <string.h>

#define u16 short unsigned

u16 solution(const char str[1000], const u16 size) {
  u16 left = 0;
  u16 diamond = 0;
  for (u16 i = 0; i < size; i++) {
    if (str[i] == '<')
      left++;
    // else if (str[i] == '>' && left > 0) {
    //   left--;
    //   diamond++;
    // }
    else if (str[i] == '>' && left > diamond)
      diamond++;
  }
  return diamond;
}
int main(int argc, char *argv[]) {
  char str[1000];
  scanf("%s", str);
  printf("%hu\n", solution(str, strlen(str)));
  return 0;
}
