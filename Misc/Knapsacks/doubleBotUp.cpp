#include <bits/stdc++.h>
#define maxN 31
#define maxW 31
using namespace std;

// 3D array to store
// states of DP
int dp[maxN][maxW][maxW];

// Function to calculate
// maximum weight that can be put
// into the knapsacks
int maxWeight(int *arr, int n, int w1, int w2) {
  // Iterate over all possible states
  for (int i = 0; i <= n; i++) {
    for (int w1_r = 0; w1_r <= w1; w1_r++) {
      for (int w2_r = 0; w2_r <= w2; w2_r++) {
        // Base case
        if (i == 0)
          dp[i][w1_r][w2_r] = 0;
        // If the current item can be put in
        // the first knapsack
        else if (arr[i - 1] <= w1_r && arr[i - 1] <= w2_r)
          dp[i][w1_r][w2_r] =
              max(arr[i - 1] + dp[i - 1][w1_r - arr[i - 1]][w2_r],
                  max(arr[i - 1] + dp[i - 1][w1_r][w2_r - arr[i - 1]],
                      dp[i - 1][w1_r][w2_r]));

        // If the current item can be put in
        // the second knapsack
        else if (arr[i - 1] <= w2_r)
          dp[i][w1_r][w2_r] =
              max(arr[i - 1] + dp[i - 1][w1_r][w2_r - arr[i - 1]],
                  dp[i - 1][w1_r][w2_r]);

        // If the current item can be put in
        // the first knapsack
        else if (arr[i - 1] <= w1_r)
          dp[i][w1_r][w2_r] =
              max(arr[i - 1] + dp[i - 1][w1_r - arr[i - 1]][w2_r],
                  dp[i - 1][w1_r][w2_r]);

        // If the current item can not be put in
        // either of the knapsacks
        else
          dp[i][w1_r][w2_r] = dp[i - 1][w1_r][w2_r];
      }
    }
  }

  // Return the maximum weight that can be put
  // into the knapsacks
  return dp[n][w1][w2];
}

// Driver code
int main() {
  // Input array
  int arr[] = {8, 2, 3};
  // Number of elements in the array
  int n = sizeof(arr) / sizeof(arr[0]);

  // Capacity of knapsacks
  int w1 = 10, w2 = 3;

  // Function to be called
  cout << maxWeight(arr, n, w1, w2);
  return 0;
}
