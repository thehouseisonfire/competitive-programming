#include <iomanip>
#include <iostream>

using namespace std;

int main() {

  double n, m;
  cin >> n >> m;

  double media = (n * 3.5 + m * 7.5) / 11.0;

  cout << "MEDIA = " << fixed << setprecision(5) << media << endl;

  return 0;
}
