#include <iostream>
#include <utility>
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

int solution(int ind1, int ind2, string &s1, string &s2,
             vector<vector<short int>> &results) {
  if (ind1 == s1.size())
    return s2.size() - ind2;
  if (ind2 == s2.size())
    return s1.size() - ind1;

  if (results[ind1][ind2] != -1)
    return results[ind1][ind2];

  ll res = INF;
  ll remove = 1 + solution(ind1 + 1, ind2, s1, s2, results);
  ll edit = 1 + solution(ind1 + 1, ind2 + 1, s1, s2, results);
  ll add = 1 + solution(ind1, ind2 + 1, s1, s2, results);
  ll nothing = s1[ind1] == s2[ind2]
                   ? solution(ind1 + 1, ind2 + 1, s1, s2, results)
                   : INF;

  res = min(res, remove);
  res = min(res, edit);
  res = min(res, add);
  res = min(res, nothing);

  return results[ind1][ind2] = res;
}

const short int MAX = 5000 + 1;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1, s2;
  vector<vector<short int>> results(MAX, vector<short int>(MAX, -1));
  cin >> s1 >> s2;

  cout << solution(0, 0, s1, s2, results) << endl;

  return 0;
}
