#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int i = 8, j;
  char r = 'S';
  while (i--) {
    cin >> j;
    if (j == 9)
      r = 'F';
  }
  cout << r << endl;
  return 0;
}
