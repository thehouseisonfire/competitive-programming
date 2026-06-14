#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

inline int64 choose2(int64 x) { return x * (x - 1) / 2; }

inline int64 total_pairs(int64 n) { return choose2(n * n); }

int64 two_knights(int64 n) {
  int64 total = total_pairs(n);
  int64 attacks = (n >= 3) ? 4 * (n - 1) * (n - 2) : 0;
  return total - attacks;
}

int64 two_rooks(int64 n) { return total_pairs(n) - n * choose2(n) * 2; }

int64 two_bishops(int64 n) {
  return total_pairs(n) - n * (n - 1) * (2 * n - 1) / 3;
}

int64 two_queens(int64 n) {
  return total_pairs(n) - n * choose2(n) * 2 - n * (n - 1) * (2 * n - 1) / 3;
}

int64 C(int64 n, int64 k) {
  if (k < 0 || k > n)
    return 0;
  int64 res = 1;
  for (int64 i = 1; i <= k; i++) {
    res = res * (n - k + i) / i;
  }
  return res;
}

int64 factorial(int64 k) {
  int64 res = 1;
  for (int64 i = 2; i <= k; i++)
    res *= i;
  return res;
}

int64 k_rooks(int64 n, int64 k) { return C(n, k) * C(n, k) * factorial(k); }

int main() {
  int64 n;
  cin >> n;

  cout << "Knights: " << two_knights(n) << "\n";
  cout << "Rooks:   " << two_rooks(n) << "\n";
  cout << "Bishops: " << two_bishops(n) << "\n";
  cout << "Queens:  " << two_queens(n) << "\n";
}
