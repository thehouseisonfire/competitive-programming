#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  int n, m;
  cin >> n >> m;
  vector<int> v(n), w(n);
  vector<int> dp(m + 1);
  for (auto &pos : w)
    cin >> pos;
  for (auto &pos : v)
    cin >> pos;

  for (int i = 0; i < n; i++) {
    for (int j = m; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[m] << endl;
  return 0;
}
