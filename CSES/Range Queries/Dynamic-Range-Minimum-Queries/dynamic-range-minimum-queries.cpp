#include <iostream>
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

#define INPUT_VEC(v, n)                                                        \
  for (size_t i = n; i < n + n; i++)                                           \
    cin >> v[i];

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

const long MAX = 2 * 1e5;
int n;
vector<int> v(2 * MAX);

int op(int a, int b) { return min(a, b); }

void build() {
  for (int i = n - 1; i > 0; --i)
    v[i] = op(v[i << 1], v[i << 1 | 1]);
}

void modify(int p, int val) {
  for (v[p += n] = val; p > 1; p >>= 1)
    v[p >> 1] = op(v[p], v[p ^ 1]);
}

// [a, b), does not include `b`
ll query(int l, int r) {

  ll res = 10e9 + 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res = op(v[l++], res);
    if (r & 1)
      res = op(v[--r], res);
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> n >> q;
  INPUT_VEC(v, n)
  build();
  while (q--) {
    int k, a, b;
    cin >> k >> a >> b;
    a--;
    if (k == 1)
      modify(a, b);
    if (k == 2)
      cout << query(a, b) << endl;
  }
  return 0;
}
