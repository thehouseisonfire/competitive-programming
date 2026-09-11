#include <algorithm>
#include <iostream>
#include <vector>
#define u16 short unsigned

#define PRINT_VEC(v)                                                           \
  for (const auto &pos : v) {                                                  \
    cout << pos << " ";                                                        \
  }                                                                            \
  cout << endl;

#define PRINT_DUO_VEC(v)                                                       \
  for (const auto &pos : v) {                                                  \
    cout << pos.first << " " << pos.second << endl;                            \
  }                                                                            \
  cout << endl;

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    vector<u16> vec(m);
    INPUT_VEC(vec);
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size() - 1; i++) {
      cout << vec[i] << " ";
    }
    cout << vec[vec.size() - 1] << endl;
  }
  return 0;
}
