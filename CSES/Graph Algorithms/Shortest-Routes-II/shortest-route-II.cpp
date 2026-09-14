#include <climits>
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

#define INF LLONG_MAX
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

const int MAX = 505;
ll n;
ll mtx[MAX][MAX];

void start() {
  for (ll k = 0; k < MAX; k++) {
    for (ll i = 0; i < MAX; i++) {
      if (i == k)
        mtx[i][k] = 0;
      else
        mtx[i][k] = INF;
    }
  }
}

void solution() {
  for (ll k = 0; k < n; k++) {
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        if (mtx[i][k] < INF && mtx[k][j] < INF)
          mtx[i][j] = min(mtx[i][j], mtx[i][k] + mtx[k][j]);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  start();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll m, o;
  cin >> n >> m >> o;
  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    c = min(c, mtx[a][b]);
    mtx[a][b] = c;
    mtx[b][a] = c;
  }
  solution();
  for (ll i = 0; i < o; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    const auto res = mtx[a][b];
    cout << (res != INF ? res : -1) << endl;
  }

  return 0;
}
