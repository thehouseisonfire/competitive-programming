#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double n;
  cin >> n;

  cout << fixed << setprecision(3);
  cout << "VOLUME = " << (4.0 / 3.0) * 3.14159 * n * n * n << endl;

  return 0;
}
