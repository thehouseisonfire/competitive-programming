#include <stdio.h>

int solution(int n, int *nums) {
  int avg = 0;
  for (int i = 0; i < n; i++)
    avg += nums[i];
  if (avg % n)
    return -1;
  avg /= n;
  int sum = 1;
  printf("avg: %d\n", avg);
  for (int i = 0; i < n; i++) {
    if (avg < nums[i])
      break;
    sum += avg - nums[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int nums[n];
  for (int i = 0; i < n; i++) {
    int aux;
    scanf("%d", &aux);
    nums[i] = aux;
  }
  printf("\nn: %d\n", n);
  for (int i = 0; i < n; i++)
    printf("%d ", nums[i]);
  printf("\n--------\n");
  printf("%d\n\n", solution(n, nums));
  return 0;
}
