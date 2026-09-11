#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (size_t j = 0; j < k; j++) {
      int f;
      cin >> f;
      switch (f) {
      case 1:
        cout << "Rolien" << endl;
        break;
      case 2:
        cout << "Naej" << endl;
        break;
      case 3:
        cout << "Elehcim" << endl;
        break;
      case 4:
        cout << "Odranoel" << endl;
        break;
      }
    }
  }
  return 0;
}
