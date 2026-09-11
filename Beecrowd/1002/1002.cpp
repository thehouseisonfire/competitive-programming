#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double raio;
  const double pi = 3.14159;
  cin >> raio;
  double area = pi * raio * raio;
  cout << "A=" << fixed << setprecision(4) << area << endl;

  return 0;
}
