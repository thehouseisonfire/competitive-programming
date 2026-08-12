#include <iostream>

using namespace std;

int solution(int n, int *nums) {
  int avg = 0;
  for (int i = 0; i < n; i++)
    avg += nums[i];

  if (avg % n)
    return -1;

  avg /= n;

  int sum = 1;
  for (int i = 0; i < n; i++) {
    if (avg < nums[i])
      break;
    sum += avg - nums[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int n;

  while (cin >> n) {
    int nums[n];

    for (int i = 0; i < n; i++)
      cin >> nums[i];

    cout << solution(n, nums) << endl;
  }
  return 0;
}
