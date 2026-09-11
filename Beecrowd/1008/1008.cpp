#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  long long n, m;
  double o;

  cin >> n >> m >> o;

  cout << "NUMBER = " << n << endl;
  cout << "SALARY = U$ " << fixed << setprecision(2) << m * o << endl;

  return 0;
}
