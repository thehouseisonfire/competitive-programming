#include <deque>
#include <iostream>

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

  int n;
  cin >> n;
  deque<int> v;
  v.resize(n + 1);
  for (int i = n; i >= 0; i--)
    cin >> v[i];

  int count = 0;
  while (!(v.size() == 1 && v[0] == 1)) {
    if (v[0] == 1) {
      deque<int> w(v.size() + 1);
      for (int i = 0; i < v.size(); ++i) {
        if (v[i]) {
          w[i] = (w[i] + 1) % 2;
          w[i + 1] = (w[i + 1] + 1) % 2;
        }
      }
      w[0] = (w[0] + 1) % 2;
      while (w.size() > 1 && w.back() == 0)
        w.pop_back();
      v.swap(w);
    } else {
      v.pop_front();
      if (v.empty())
        v.push_back(0);
    }
    count++;
  }

  cout << count << endl;
  return 0;
}
