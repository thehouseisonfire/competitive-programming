#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

#define bufsize 400

// int compare(const void *a, const void *b) { return *(const char *)a - *(const
// char *)b; }
int compare(const void *a, const void *b) {
  const int i = *(const int *)a;
  const int j = *(const int *)b;
  return (i > j) - (i < j);
}

// 400   401
//  40   4 401
//   4   04 401
#define bufsize 400
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  char buf[bufsize], buf2[bufsize];
  //
  fgets(buf, bufsize, stdin);
  int len = strlen(buf);

  if (len < bufsize || buf[bufsize - 1] == ' ') {
    // no need for treatment, go somewhere else
  }
  fgets(buf2, bufsize, stdin);
  // int last_space = bufsize - 1;
  // while (buf[last_space] != ' ')
  //   last_space--;
  // strtol apartir do ultimo espaco
  char *ptr = buf, *endptr;
  int count = 0;
  while (*ptr != ' ') {
    ptr--;
    count++;
  }
  int i = strtol(ptr, &endptr, 10);
  printf("%d", i);
  return 0;
  //
  int first = 1;
  while (n--) {
    int first_space;
    fgets(buf, bufsize, stdin);
    int len = strlen(buf);
    if (len < bufsize || buf[bufsize - 1] == ' ') {
      // no need for treatment, go somewhere else
    }
    fgets(buf2, bufsize, stdin);
    int last_space = bufsize - 1;
    while (buf[last_space] != ' ')
      last_space--;
    // strtol apartir do ultimo espaco
  }
  return 0;
}
