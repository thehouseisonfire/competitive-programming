#include <iostream>
#include <map>
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

  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  INPUT_VEC(v);

  ll best = 0;
  map<ll, ll> mapa;

  for (ll l = 0, r = 0, curr = 0; r < n; r++) {
    if (mapa[v[r]]) {
      curr += v[r];
      mapa[v[r]]++;
    } else {
      mapa[v[r]] = 1;
      curr += v[r];
    }

    while (mapa.size() > k) {
      if (mapa[v[l]] == 1) {
        curr -= v[l];
        mapa.erase(v[l]);
      } else {
        curr -= v[l];
        mapa[v[l]]--;
      }
      l++;
    }

    best = max(best, curr);
  }

  cout << best << endl;

  return 0;
}
