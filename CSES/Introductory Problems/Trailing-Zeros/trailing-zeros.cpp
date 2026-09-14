#include <bits/stdc++.h>

using namespace std;

int solution(const int n) {
  int count = 0;
  int divider = 5;
  while (n >= divider) {
    count += n / divider;
    divider *= 5;
  }
  return count;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cout << solution(n) << endl;
  return 0;
}
