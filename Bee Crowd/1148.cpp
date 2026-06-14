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

void floydWarshall(vector<vector<ll>> &mtx) {

  for (ll k = 0; k < mtx.size(); k++) {
    for (ll i = 0; i < mtx.size(); i++) {
      for (ll j = 0; j < mtx.size(); j++) {
        if (mtx[i][j] > (mtx[i][k] + mtx[k][j]) &&
            (mtx[k][j] != INF && mtx[i][k] != INF))
          mtx[i][j] = mtx[i][k] + mtx[k][j];
      }
    }
  }
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      return 0;
    vector<vector<ll>> mtx(n, vector<ll>(n, INF));
    while (m--) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      mtx[a][b] = c;
      if (mtx[a][b] != INF && mtx[b][a] != INF) {
        mtx[a][b] = 0;
        mtx[b][a] = 0;
      }
    }
    floydWarshall(mtx);
    ll q;
    cin >> q;
    while (q--) {
      ll a, b;
      cin >> a >> b;
      a--, b--;
      if (mtx[a][b] == INF)
        cout << "Nao e possivel entregar a carta" << endl;
      else
        cout << mtx[a][b] << endl;
    }
    cout << endl;
  }
}
