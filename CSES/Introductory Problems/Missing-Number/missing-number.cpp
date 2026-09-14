#include <iostream>

int main(int argc, char *argv[]) {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long n, sum;
  cin >> n;
  sum = (n * n + n) / 2;
  for (int i = 0; i < n - 1; i++) {
    int diff;
    cin >> diff;
    sum -= diff;
  }
  cout << sum << endl;
  return 0;
}
