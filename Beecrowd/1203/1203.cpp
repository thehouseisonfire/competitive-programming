#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n, 0);
    const int k = m;
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      v[a]++, v[b]++;
    }
    long long sum = 0;
    for (const auto &pos : v)
      sum += pos;
    vector<bool> w(sum + 1);
    w[0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = w.size() - 1; j >= 0; j--) {
        if (j + v[i] <= sum)
          w[j + v[i]] = w[j + v[i]] || w[j];
      }

    if (w[k])
      cout << 'S' << endl;
    else
      cout << 'N' << endl;
  }
  return 0;
}
