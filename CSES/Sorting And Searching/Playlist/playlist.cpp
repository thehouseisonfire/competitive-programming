#include <iostream>
#include <unordered_map>

using namespace std;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int sum = 0;
  unordered_map<int, int> map;
  map.reserve(n);
  int max = 1, min = 0;
  for (size_t i = 1; i <= n; i++) {
    int aux;
    cin >> aux;
    if (!map[aux] || map[aux] < min) {
      sum++;
    } else {
      if (sum > max)
        max = sum;
      sum = i - map[aux];
      min = map[aux];
    }
    map[aux] = i;
  }
  if (sum > max)
    max = sum;

  cout << max << endl;
  return 0;
}
