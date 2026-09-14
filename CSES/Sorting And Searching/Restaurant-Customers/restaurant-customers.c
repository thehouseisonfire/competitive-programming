#include <stdio.h>
#include <stdlib.h>

#define u8 unsigned char
#define hu short unsigned
#define lu unsigned
#define llu long long unsigned
#define ld short int
#define ll long long

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

// int compare(const void *a, const void *b) { return *(const char *)a - *(const
// char *)b; }
int compare(const void *a, const void *b) {
  const int i = *(const int *)a;
  const int j = *(const int *)b;
  return (i > j) - (i < j);
}

int main(int argc, char *argv[]) {
  llu n;
  enum e { size = sizeof(size_t) };
  scanf("%llu", &n);
  size_t *v1 = (size_t *)malloc(n * size);
  size_t *v2 = (size_t *)malloc(n * size);
  for (int i = 0; i < n; i++)
    scanf("%ld %ld", v1 + i, v2 + i);
  qsort(v1, n, size, compare);
  qsort(v2, n, size, compare);
  size_t i = 0, j = 0, count = 0, max_count = 0;
  while (i < n) {
    if (v1[i] < v2[j]) {
      count++, i++;
      if (count > max_count)
        max_count = count;
    } else {
      count--, j++;
    }
  }
  free(v1);
  free(v2);
  printf("%lu\n", max_count);
  return 0;
}
