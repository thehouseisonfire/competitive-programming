
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum required value
float knapSack(int W, float wt[], float val[], int n) {

  // maxratio will store the maximum value to weight
  // ratio we can have for any item and maxindex
  // will store the index of that element
  float maxratio = INT_MIN;
  int maxindex = 0;

  // Find the maximum ratio
  for (int i = 0; i < n; i++) {
    if ((val[i] / wt[i]) > maxratio) {
      maxratio = (val[i] / wt[i]);
      maxindex = i;
    }
  }

  // The item with the maximum value to
  // weight ratio will be put into
  // the knapsack repeatedly until full
  return (W * maxratio);
}

// Driver code
int main() {
  float val[] = {14, 27, 44, 19};
  float wt[] = {6, 7, 9, 8};
  int n = sizeof(val) / sizeof(val[0]);
  int W = 50;

  cout << knapSack(W, wt, val, n);

  return 0;
}
