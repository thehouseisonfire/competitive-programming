#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, x;
  cin >> n >> m >> x;

  int y = (n + m + abs(n - m)) / 2;
  y = (y + x + abs(y - x)) / 2;

  cout << y << " eh o maior" << endl;

  return 0;
}
