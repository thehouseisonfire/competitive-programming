#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 100010

using namespace std;

int dp[MAXN], tab[MAXN], best[MAXN], vetor[MAXN], n, m;

int solve(int pos) {
  if (pos >= n)
    return 0;
  if (tab[pos] != -1)
    return tab[pos];
  return tab[pos] = max(vetor[pos] + solve(pos + 2), solve(pos + 1));
}

int func(int line) {
  if (line >= m)
    return 0;
  if (dp[line] != -1)
    return dp[line];
  return dp[line] = max(best[line] + func(line + 2), func(line + 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); // Fast input/output

  while (cin >> m >> n && (n || m)) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> vetor[j];
        tab[j] = -1; // Initialize memoization array
      }
      dp[i] = -1;         // Initialize memoization array
      best[i] = solve(0); // Compute best result for the current line
    }
    cout << func(0) << "\n"; // Output the result
  }

  return 0;
}
