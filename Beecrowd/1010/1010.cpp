#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, x, y;
  float a, b;

  cin >> n >> m >> a;
  cin >> x >> y >> b;

  cout << fixed << setprecision(2);
  cout << "VALOR A PAGAR: R$ " << m * a + y * b << endl;

  return 0;
}
