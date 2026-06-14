#include <iostream>
#include <vector>

#define ll long long

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

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<ll> v(n);
  INPUT_VEC(v);
  vector<ll> res(m + 1);
  res[0] = 1;
  for (const auto &pos : v) {
    for (ll i = 1; i <= m; i++) {
      if (i >= pos)
        res[i] += res[i - pos];
    }
  }
  PRINT_VEC(res);

  return 0;
}
