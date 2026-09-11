#include <iostream>

using namespace std;

const int MAX = 1e9 + 7;

int main(int argc, char *argv[]) {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m)
      return 0;
    int min = MAX;
    while (n--) {
      int aux;
      cin >> aux;
      if (aux < min)
        min = aux;
    }
    int count = 0;
    while (m--) {
      int aux;
      cin >> aux;
      if (aux <= min)
        count++;
    }
    cout << (count < 2 ? 'Y' : 'N') << endl;
  }
  return 0;
}
