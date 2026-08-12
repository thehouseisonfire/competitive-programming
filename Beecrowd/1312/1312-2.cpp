#include <algorithm> // For std::max
#include <iostream>
#include <vector>

#define ll long long
#define PRINT_VEC(v)                                                           \
  for (const auto &pos : v) {                                                  \
    std::cout << pos << " ";                                                   \
  }                                                                            \
  std::cout << std::endl;

int main() {
  while (true) {
    int N;
    std::cin >> N;
    if (N == 0)
      break; // Stop when input is 0

    // Read the triangle input into a 2D vector
    std::vector<std::vector<int>> triangle(N);
    for (int i = 0; i < N; ++i) {
      triangle[i].resize(i + 1);
      for (int j = 0; j <= i; ++j) {
        std::cin >> triangle[i][j];
      }
    }

    // DP from the bottom of the triangle up to the top
    for (int i = N - 2; i >= 0; --i) { // Start from the second last row
      for (int j = 0; j <= i; ++j) {
        // Update the current element to include the maximum of the paths below
        triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    }

    // The answer is stored at the top of the triangle
    std::cout << triangle[0][0] << std::endl;
  }

  return 0;
}
