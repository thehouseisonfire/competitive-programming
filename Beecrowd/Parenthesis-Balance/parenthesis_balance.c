#include <stdio.h>
#include <string.h>

#define u16 short unsigned

int main(int argc, char *argv[]) {
  // driver
  char str[1000];
  scanf("%s", str);

  // solution
  u16 left = 0;
  u16 right = 0;
  for (u16 i = 0; i < strlen(str); i++) {
    switch (str[i]) {
    case ')':
      if (left <= right) {
        printf("incorrect\n");
        return 0;
      }
      right++;
      break;
    case '(':
      left++;
      break;
    }
  }
  left == right ? printf("incorrect\n") : printf("correct\n");
  return 0;
}
