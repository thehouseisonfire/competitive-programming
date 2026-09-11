#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double n, m, x;
  cin >> n >> m >> x;

  cout << fixed << setprecision(3);
  cout << "TRIANGULO: " << n * x / 2.0 << endl;
  cout << "CIRCULO: " << 3.14159 * x * x << endl;
  cout << "TRAPEZIO: " << (n + m) * x / 2.0 << endl;
  cout << "QUADRADO: " << m * m << endl;
  cout << "RETANGULO: " << n * m << endl;

  return 0;
}
