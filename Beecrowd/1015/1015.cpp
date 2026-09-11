#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double n, m, x, y;
  cin >> n >> m >> x >> y;

  n -= x;
  m -= y;

  cout << fixed << setprecision(4);
  cout << sqrt(n * n + m * m) << endl;

  return 0;
}
