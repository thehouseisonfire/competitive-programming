#include <climits>
#include <iostream>

using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {
    unsigned long long q;
    cin >> q;

    if (q == 64)
      q = ULLONG_MAX;
    else
      q = (1ULL << q) - 1;
    q = (q / 12000);
    cout << q << " kg" << endl;
  }
  return 0;
}
