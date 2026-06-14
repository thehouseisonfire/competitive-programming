#include <array>
#include <iostream>
#include <queue>
#include <set>

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

#define MAX 100000
#define NO_MUL 55000

ll flood(const set<ll> &s, ll n, ll m, ll o) {

  queue<pll> q;
  array<bool, 400000> visited{};

  visited[n] = 1;
  q.push({n, 0});

  int res = -1;

  while (!q.empty()) {
    auto [curr, next] = q.front();
    q.pop();

    if (curr == m) {
      res = next;
      break;
    }

    if (s.count(curr))
      continue;

    if (curr + 1 <= MAX && !visited[curr + 1]) {
      q.push({curr + 1, next + 1});
      visited[curr + 1] = 1;
    }
    if (curr - 1 > 0 && !visited[curr - 1]) {
      q.push({curr - 1, next + 1});
      visited[curr - 1] = 1;
    }
    if (!(curr % 2) && !visited[curr >> 1]) {
      q.push({curr >> 1, next + 1});
      visited[curr / 2] = 1;
    }
    if ((curr << 1) <= MAX && curr != NO_MUL && !visited[curr << 1]) {
      q.push({curr << 1, next + 1});
      visited[curr * 2] = 1;
    }
    if ((curr * 3) <= MAX && curr != NO_MUL && !visited[curr * 3]) {
      q.push({curr * 3, next + 1});
      visited[curr * 3] = 1;
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m, o;

  while (cin >> n >> m >> o) {
    if (!n && !m && !o)
      break;
    set<ll> s;

    while (o--) {
      ll aux;
      cin >> aux;
      s.insert(aux);
    }

    ll res = flood(s, n, m, o);

    cout << res << endl;
  }

  return 0;
}
