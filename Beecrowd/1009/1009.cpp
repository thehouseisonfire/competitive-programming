#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  double n, m;

  cin >> s >> n >> m;

  cout << fixed << setprecision(2);
  cout << "TOTAL = R$ " << n + m * 0.15 << endl;
}
