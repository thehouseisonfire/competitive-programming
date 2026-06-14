#include <iostream>
#include <unordered_map>

#define u16 short unsigned

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  u16 n, r;
  while (cin >> n >> r) {
    unordered_map<u16, bool> returned;
    for (u16 i = 0; i < r; i++) {
      u16 aux;
      cin >> aux;
      returned[aux] = true;
    }
    if (n == r) {
      cout << "*\n";
      continue;
    }
    for (u16 i = 1; i < n + 1; i++)
      if (!returned[i])
        cout << i << " ";
    cout << endl;
  }
  return 0;
}
