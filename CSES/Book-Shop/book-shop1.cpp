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

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

int solution(const int space, const int n, vector<int> costs,
             vector<int> values, vector<vector<int>> &results) {

  if (space == 0 || n == 0)
    return 0;

  if (results[space][n] != -1)
    return results[space][n];

  const auto cost = costs[n - 1];
  const auto value = values[n - 1];

  int pick = 0;

  if (cost <= space) {
    pick = value + solution(space - cost, n - 1, costs, values, results);
  }

  int notPick = solution(space, n - 1, costs, values, results);

  return results[space][n] = max(pick, notPick);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> costs(n);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    cin >> costs[i];
  for (int i = 0; i < n; ++i)
    cin >> values[i];

  vector<vector<int>> res(m + 1, vector<int>(n + 1, -1));
  vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
  cout << solution(m, n, costs, values, res) << endl;
  return 0;
}
