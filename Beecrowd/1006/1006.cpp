#include <iomanip>
#include <iostream>

using namespace std;

int main() {

  double n, m, o;
  cin >> n >> m >> o;

  double media = (n * 2 + m * 3 + o * 5) / 10;

  cout << "MEDIA = " << fixed << setprecision(1) << media << endl;

  return 0;
}
