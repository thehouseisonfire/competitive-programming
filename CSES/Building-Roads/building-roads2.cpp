#include <iostream>
#include <queue>
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<int> reps;
  vector<bool> visited(n);
  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue;
    queue<int> q;
    q.push(i);
    visited[i] = true;
    reps.push_back(i);
    while (!q.empty()) {
      const auto curr = q.front();
      q.pop();
      for (const auto pos : v[curr]) {
        if (visited[pos])
          continue;
        visited[pos] = true;
        q.push(pos);
      }
    }
  }

  cout << reps.size() - 1 << endl;
  const auto rep = reps[0];
  for (int i = 1; i < reps.size(); i++) {
    DUO(rep + 1, reps[i] + 1);
  }

  return 0;
}
