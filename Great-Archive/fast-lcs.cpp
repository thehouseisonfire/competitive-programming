#include <bitset>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Bitset LCS for N <= 50000 (Adjust size as needed)
// Time Complexity: O(N * M / 64)
// Space Complexity: O(N * M / 64)
const int MAXN = 50000;

void solve_bitset() {
  string s, t;
  cin >> s >> t;

  // Precompute positions for each character in S
  // This allows us to "lookup" matches in parallel
  map<char, bitset<MAXN>> pos;
  for (int i = 0; i < s.size(); i++) {
    pos[s[i]].set(i);
  }

  bitset<MAXN> row; // Represents the current DP row

  for (char c : t) {
    // This magic formula is equivalent to the LCS recurrence:
    // row[j] = row[j-1] if match, else max(...)
    // But done 64 bits at a time.

    bitset<MAXN> match = pos[c];
    bitset<MAXN> x = row | match;

    // Logical shift to propagate carries
    bitset<MAXN> y = row;
    y = (row << 1);
    y.set(0); // Effectively carrying in a 1

    // This subtraction logic is tricky with bitsets, usually implemented as:
    // (x - y) in standard arithmetic. Since std::bitset doesn't support
    // subtraction, we use the equivalent: x & (~(x - y)) -> x ^ (x & (x - y))
    // But for CP, a slightly different standard trick is often used (Pragmatic
    // LCS). A common simpler variation for length ONLY is effectively:

    /*
       The bitset trick for LCS is slightly complex to write from scratch
       without a custom bitset class that supports subtraction. Standard
       std::bitset doesn't support arithmetic subtraction.

       Most CPers use a custom struct or compiler intrinsics for this.
       However, for N <= 50000, bitset is the way to go if you have the class.
    */
  }
  // Note: Implementing full bitset LCS requires a custom bitset class
  // because std::bitset doesn't do subtraction.
}
