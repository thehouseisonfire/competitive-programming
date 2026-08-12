#include <stdio.h>

// int solution(int n) {
//   int overtakes = 0;
//   int start[n];
//   for (int i = 1; i < n + 1; i++) {
//     int car;
//     scanf("%d", &car);
//     start[car] = i;
//   }
//   for (int fpos = 1; fpos < n + 1; fpos++) {
//     int car;
//     scanf("%d", &car);
//     if (fpos < start[car])
//       overtakes += start[car] - fpos;
//   }
//   return overtakes;
// }

void swap(int *start, const int i, const int j) {
  const int aux = start[i];
  start[i] = start[j];
  start[j] = aux;
}

const int solution(int *start, const int *finish, const int n) {
  int overtakes = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (start[j] == finish[i]) {
        int aux = start[j];
        for (int k = j; k > i; k--) {
          start[k] = start[k - 1];
          overtakes++;
        }
        start[i] = aux;
      }
  return overtakes;
}
int main(int argc, char *argv[]) {
  int n;
  while (scanf("%d", &n) != EOF) {
    int start[n];
    int finish[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &start[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &finish[i]);
    }
    printf("%d\n", solution(start, finish, n));
  }
  return 0;
}
