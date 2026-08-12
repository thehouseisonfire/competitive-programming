#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define u8 unsigned char
#define u16 short unsigned
#define arr_size (100000 >> 5) + 1

int main(int argc, char *argv[]) {
  unsigned arr[arr_size] = {0};
  char buffer[100];
  fgets(buffer, 100, stdin);
  u8 buf_size = strlen(buffer);
  u16 offset = 0;
  while (buf_size) {
    for (u8 i = 0; i < 100; i++) {
      arr[buffer[i] >> 5] += 2 << buffer[i];
    }
  }
  // printf("%s\n");
  return 0;
}
