#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, prev;
  cin >> n >> prev;
  long long count = 0;
  for (; n > 1; n--) {
    int aux;
    cin >> aux;
    if (aux < prev)
      count += prev - aux;
    else
      prev = aux;
  }
  cout << count << endl;
  return 0;
}
