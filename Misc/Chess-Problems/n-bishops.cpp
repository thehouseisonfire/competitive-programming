#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/combinatorics/bishops-on-chessboard.html

// returns the number of squares in diagonal i
int squares(int i) {

  if ((i & 1) == 1)
    return i / 4 * 2 + 1;
  else
    return (i - 1) / 4 * 2 + 2;
}

// returns the number of ways to fill a
// n * n chessboard with k bishops so
// that no two bishops attack each other.
long bishop_placements(int n, int k) {
  // return 0 if the number of valid places to be
  // filled is less than the number of bishops
  if (k > 2 * n - 1)
    return 0;

  // dp table to store the values
  long dp[n * 2][k + 1];

  // Setting the base conditions
  for (int i = 0; i < n * 2; i++) {
    for (int j = 0; j < k + 1; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < n * 2; i++)
    dp[i][0] = 1;
  dp[1][1] = 1;

  // calculate the required number of ways
  for (int i = 2; i < n * 2; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 2][j] + dp[i - 2][j - 1] * (squares(i) - j + 1);
    }
  }

  // stores the answer
  long ans = 0;
  for (int i = 0; i <= k; i++) {
    ans += dp[n * 2 - 1][i] * dp[n * 2 - 2][k - i];
  }

  return ans;
}

int main() {
  int n = 2;
  int k = 2;
  long ans = bishop_placements(n, k);
  cout << (ans);
}
