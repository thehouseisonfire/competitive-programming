#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  long long n;
  cin >> n;
  while (n > 0) {
    n--;
    long long aux;
    cin >> aux;

    long long res = (-1.0 + sqrt(1.0 + 24.0 * aux)) / 6.0;
    cout << res << endl;
  }

  return 0;
}
