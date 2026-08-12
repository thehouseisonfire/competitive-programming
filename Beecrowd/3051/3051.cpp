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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, k, sum = 0;
  cin >> n >> k;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    ll aux;
    cin >> aux;
    v[i] = aux;
    // sum += aux;
    // v[i] = sum;
  }
  // PRINT_VEC(v);

  ll start = 0, end = 0, curr = v[0], res = 0;
  while (start < n) {
    if (curr == k) {
      res++;
      DUO(start, end);
      if (end < n - 1) {
        end++, curr += v[end];
      } else {
        curr -= v[start], start++;
      }
    } else if (curr < k) {
      if (end < n - 1) {
        end++, curr += v[end];
      } else {
        break;
      }
    } else if (curr > k) {
      curr -= v[start], start++;
      if (start > end) {
        if (end < n - 1) {
          end++, curr += v[end];
        } else {
          break;
        }
      }
    }
    // DUO(start, end);
    // cout << curr << endl;
  }
  cout << res << endl;

  return 0;
}
