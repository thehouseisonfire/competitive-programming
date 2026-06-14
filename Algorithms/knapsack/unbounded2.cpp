
// C++ program to implement optimized Unbounded Knapsack
// algorithm
#include <bits/stdc++.h>
using namespace std;

// Function to implement optimized
// Unbounded Knapsack algorithm
int unboundedKnapsackBetter(int W, vector<int> val, vector<int> wt) {

  // Stores most dense item
  int maxDenseIndex = 0;

  // Find the item with highest unit value
  // (if two items have same unit value then choose the
  // lighter item)
  for (int i = 1; i < val.size(); i++) {
    if (val[i] / wt[i] > val[maxDenseIndex] / wt[maxDenseIndex] ||
        (val[i] / wt[i] == val[maxDenseIndex] / wt[maxDenseIndex] &&
         wt[i] < wt[maxDenseIndex])) {
      maxDenseIndex = i;
    }
  }

  int dp[W + 1] = {0};

  int counter = 0;
  bool breaked = false;
  int i = 0;
  for (i = 0; i <= W; i++) {
    for (int j = 0; j < wt.size(); j++) {
      if (wt[j] <= i) {
        dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
      }
    }
    if (i - wt[maxDenseIndex] >= 0 &&
        dp[i] - dp[i - wt[maxDenseIndex]] == val[maxDenseIndex]) {
      counter += 1;
      if (counter >= wt[maxDenseIndex]) {
        breaked = true;
        break;
      }
    } else {
      counter = 0;
    }
  }

  if (!breaked) {
    return dp[W];
  } else {
    int start = i - wt[maxDenseIndex] + 1;
    int times = (floor)((W - start) / wt[maxDenseIndex]);
    int index = (W - start) % wt[maxDenseIndex] + start;
    return (times * val[maxDenseIndex] + dp[index]);
  }
}

// Driver Code
int main() {
  int W = 100;
  vector<int> val = {10, 30, 20};
  vector<int> wt = {5, 10, 15};
  cout << unboundedKnapsackBetter(W, val, wt);
}

// This code is contributed by ratiagrawal.
