#include <bits/stdc++.h>

#define u64 unsigned long long

using namespace std;

void solution(int n) {

  u64 sum = ((u64)n * n + n) / 2;

  if (sum % 2) {
    cout << "NO" << endl;
    return;
  }

  u64 count = 1;
  sum >>= 1;
  u64 aux_sum = sum;

  cout << "YES" << endl;
  for (u64 i = n; aux_sum > i; i--) {
    aux_sum -= i;
    count++;
  }
  cout << count << endl;
  for (u64 i = n; sum > i; i--) {
    sum -= i;
    cout << i << " ";
  }
  cout << sum << endl;
  cout << n - count << endl;
  for (u64 i = 1; i < n + 2 - count; i++) {
    if (i != sum)
      cout << i << " ";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  u64 n;
  cin >> n;
  solution(n);
  return 0;
}
