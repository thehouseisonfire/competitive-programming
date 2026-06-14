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

#define BSIZE 255

// int compare(const void *a, const void *b) { return *(const char *)a - *(const
// char *)b; }
int compare(const void *a, const void *b) {
  const int i = *(const int *)a;
  const int j = *(const int *)b;
  return (i > j) - (i < j);
}

int main(int argc, char *argv[]) {
  char buf[BSIZE];
  while (fgets(buf, BSIZE, stdin)) {
    u8 len = strlen(buf);
  }
  // printf("%s\n");
  return 0;
}
