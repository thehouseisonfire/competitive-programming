#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double n, m;
  cin >> n >> m;
  cout << fixed << setprecision(3);
  cout << n / m << " km/l" << endl;
  return 0;
}
