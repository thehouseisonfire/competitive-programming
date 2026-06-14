#include <cstdlib>
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

const ll MAX = 1e5;
vector<vector<int>> v(MAX + 1, vector<int>(52));

int conv(char c) {
  if (c < 'a')
    return 26 + (c - 'A');

  return (c - 'a');
}

void precomp(const string &target) {
  vector<int> prefix(52, -1);
  for (int i = target.length() - 1; i >= 0; i--) {
    int c = conv(target[i]);
    v[i + 1] = prefix;
    prefix[c] = i + 1;
  }
  v[0] = prefix;
}

bool query_tree(const string &query) {
  auto prefix = v[0];
  for (ll i = 0; i < query.size(); i++) {

    char c = conv(query[i]);

    if (prefix[c] == -1)
      return false;

    prefix = v[prefix[c]];
  }
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    string target;
    cin >> target;
    precomp(target);
    ll q;
    cin >> q;
    while (q--) {
      string query;
      cin >> query;
      cout << (query_tree(query) ? "Yes" : "No") << endl;
    }
  }

  return 0;
}
