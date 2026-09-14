// https://codeforces.com/gym/105505/problem/F

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
  cin >> k >> n;

  if (k < (n + 2) / 3 || k > (n + 1) / 2) {
    cout << "*" << endl;
    return 0;
  }

  string s;
  vector<ll> v(k - 1, 1);

  ll dashes = n - k;
  ll gaps = k - 1;
  ll extra = dashes - gaps;

  ll prefix = 0, suffix = 0;
  if (extra)
    prefix = 1, extra--;

  for (auto &pos : v)
    if (extra)
      pos++, extra--;

  if (extra)
    suffix = 1;

  for (ll i = 0; i < prefix; i++)
    s.push_back('-');

  for (ll i = 0; i < k; i++) {
    s.push_back('X');
    if (i < k - 1) {
      for (ll j = 0; j < v[i]; j++)
        s.push_back('-');
    }
  }
  for (ll i = 0; i < suffix; i++)
    s.push_back('-');

  cout << s << endl;
  return 0;
}
