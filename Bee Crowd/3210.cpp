#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#define u8 unsigned char
#define hd short int
#define hu short unsigned
#define lu unsigned
#define ll long long
#define llu long long unsigned
#define float double
#define double long double
#define pi pair<int, int>
#define pll pair<ll, ll>

#define INF 2147483647
#define HINF INF >> 1
#define MOD 1000000007
#define ASCII_NUMBER_OFFSET '0'
#define ASCII_UPPERCASE_OFFSET 'A'
#define ASCII_LOWERCASE_OFFSET 'a'
// #define ASCII_NUMBER_OFFSET 48
// #define ASCII_UPPERCASE_OFFSET 65
// #define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define PI(x) cout << x.first << " " << x.second << endl
#define DUO(x, y) cout << x << " " << y << endl

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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  for (;;) {
    cin >> n;
    vector<pi> v(n);
    unordered_map<int, int> map;
    for (size_t i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      map[a] = 1;
      v[i] = {a, b};
    }
    int sum = 0;
    for (auto &pos : map) {
      sum += pos.second;
      pos.second = sum;
    }
    cin >> m;
    if (!n && !m)
      break;
    while (m--) {
      int a, b;
      cin >> a >> b;
      if (a > b)
        swap(a, b);
      int diff = n - map[a];  // years not recorded from 0 to a
      int diff2 = n - map[b]; // years not recorded from 0 to b

      // diff2 - diff = years no recorded from a to b
      if (diff2 - diff) {
        cout << "maybe" << endl;
        continue;
      }
      int year_max = v[a].first;
      int max = v[a].second;
      for (size_t i = a; i < b; i++)
        if (max < v[i].second)
          year_max = v[i].first, max = v[i].second;

      cout << (max == v[b].second);
    }
  }
  return 0;
}
