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

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int solution();
int solution(const int num, const vector<int> &choices, vector<int> &results);

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;

  int d = n, e = n, f = n;
  for (int i = 0; i < m; i++) {

    char p, p2, op;
    int q;
    cin >> op;
    if (op == 'A') {
      cin >> p >> p2 >> q;
      if (p == 'D') {
        if (p2 == 'E') {
          d += q;
          e -= q;
        }
        if (p2 == 'F') {
          d += q;
          f -= q;
        }
      }
      if (p == 'E') {

        if (p2 == 'D') {
          e += q;
          d -= q;
        }
        if (p2 == 'F') {
          e += q;
          f -= q;
        }
      }
      if (p == 'F') {

        if (p2 == 'D') {
          f += q;
          d -= q;
        }
        if (p2 == 'E') {
          f += q;
          e -= q;
        }
      }
    }
    if (op == 'C') {
      cin >> p >> q;
      if (p == 'D') {
        d -= q;
      }
      if (p == 'E') {
        e -= q;
      }
      if (p == 'F') {
        f -= q;
      }
    }
    if (op == 'V') {
      cin >> p >> q;
      if (p == 'D') {
        d += q;
      }
      if (p == 'E') {
        e += q;
      }
      if (p == 'F') {
        f += q;
      }
    }
  }
  cout << d << " " << e << " " << f << endl;
  return 0;
}
