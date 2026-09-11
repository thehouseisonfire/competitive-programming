/*
 * Bitset + Hirschberg LCS Reconstruction
 * Complexity: Time O(NM/64), Space O(N/64)
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

// Constants
using Word = uint64_t;
constexpr int WORD_SIZE = 64;

using namespace std;

class BitParallelLCS {
  vector<Word> V;
  vector<Word> P[256]; // Pattern masks for each char
  int n;               // Length of pattern (vertical string)
  int num_words;

public:
  // Initialize with the vertical string (Pattern)
  BitParallelLCS(const string &pattern) {
    n = pattern.length();
    num_words = (n + WORD_SIZE - 1) / WORD_SIZE;

    // Initialize Match Vectors (P)
    // P[char] has a bit set at index i if pattern[i] == char
    for (int i = 0; i < 256; i++) {
      P[i].resize(num_words, 0);
    }

    for (int i = 0; i < n; i++) {
      P[(unsigned char)pattern[i]][i / WORD_SIZE] |= (1ULL << (i % WORD_SIZE));
    }

    // Initialize state vector V with 0
    V.resize(num_words, 0);
  }

  // Process one character from the horizontal string (Text)
  void step(char c) {
    const vector<Word> &Pm = P[(unsigned char)c];

    Word carry_shift = 1; // The '1' injected at the bottom (index -1)
    Word borrow_sub = 0;

    for (int i = 0; i < num_words; i++) {
      Word v_curr = V[i];
      Word pm_curr = Pm[i];

      // X = PM | V
      Word X = pm_curr | v_curr;

      // Y = (V << 1) | 1 (handled via carry chain)
      // Current block shift
      Word Y = (v_curr << 1) | carry_shift;
      // Update carry for next block (top bit of current becomes bottom of next)
      carry_shift = (v_curr >> 63);

      // Calculation: Diff = X - Y (with borrow propagation)
      // We need manual borrow handling for multi-word subtraction
      Word Diff = X - Y - borrow_sub;

      // Determine outgoing borrow
      // Borrow happens if (X < Y + borrow_in)
      // Safe check to avoid overflow:
      if (X < Y || (borrow_sub && X == Y)) {
        borrow_sub = 1;
      } else {
        borrow_sub = 0;
      }

      // V_new = X & ((X - Y) ^ X)
      V[i] = X & (Diff ^ X);
    }
  }

  // Get the actual LCS length (popcount of V)
  int get_score() const {
    int score = 0;
    for (Word w : V) {
      score += __builtin_popcountll(w);
    }
    return score;
  }

  // Retrieve the full row of LCS lengths [LCS(0), LCS(1), ... LCS(n)]
  // This is needed for the Hirschberg split step
  vector<int> get_score_vector() const {
    vector<int> scores;
    scores.reserve(n + 1);
    scores.push_back(0); // LCS with empty prefix is 0

    int current = 0;
    for (int i = 0; i < n; i++) {
      int word_idx = i / WORD_SIZE;
      int bit_idx = i % WORD_SIZE;

      if ((V[word_idx] >> bit_idx) & 1) {
        current++;
      }
      scores.push_back(current);
    }
    return scores;
  }
};

// Helper: Compute only the last row of DP table using Bit-Parallel
vector<int> get_last_row(const string &A, const string &B) {
  if (A.empty())
    return vector<int>(B.length() + 1, 0);

  // A is vertical (Pattern), B is horizontal (Text)
  // Note: get_score_vector returns sizes for prefixes of A.
  // We want the sizes for prefixes of B.
  // Standard Bit-Parallel computes LCS(A, B[0..j]).
  // Wait - The state V represents the column.
  // The popcount(V) is the value at the bottom of the current column.

  BitParallelLCS solver(A);
  vector<int> row;
  row.reserve(B.length() + 1);
  row.push_back(0);

  for (char c : B) {
    solver.step(c);
    row.push_back(solver.get_score());
  }
  return row;
}

// Recursive Hirschberg
string hirschberg(const string &A, const string &B) {
  // Base cases
  if (A.empty())
    return "";
  if (B.empty())
    return "";
  if (A.length() == 1) {
    // Simple check if A[0] exists in B
    if (B.find(A[0]) != string::npos)
      return A;
    return "";
  }

  // Divide
  int a_mid = A.length() / 2;
  string A_left = A.substr(0, a_mid);
  string A_right = A.substr(a_mid);

  // Solve lengths for split
  // For A_left vs B: We need the last row (LCS scores for all B prefixes)
  // IMPORTANT: The bit-parallel class usually sets A as vertical.
  // get_last_row(A_left, B) gives LCS(A_left, B[0...j]) for all j.
  vector<int> L1 = get_last_row(A_left, B);

  // For A_right vs B: We need to reverse both to compute from the end
  string A_right_rev = A_right;
  string B_rev = B;
  reverse(A_right_rev.begin(), A_right_rev.end());
  reverse(B_rev.begin(), B_rev.end());

  vector<int> L2 = get_last_row(A_right_rev, B_rev);

  // Conquer: Find optimal split point k
  // L1[k] + L2[B.len - k] is max
  int max_val = -1;
  int k_best = -1;
  int m = B.length();

  for (int k = 0; k <= m; k++) {
    // L2 is reversed, so index corresponding to k is m - k
    if (L1[k] + L2[m - k] > max_val) {
      max_val = L1[k] + L2[m - k];
      k_best = k;
    }
  }

  // Recurse
  string res_left = hirschberg(A_left, B.substr(0, k_best));
  string res_right = hirschberg(A_right, B.substr(k_best));

  return res_left + res_right;
}

int main() {
  // Example Usage
  string A = "AGGTAB";
  string B = "GXTXAYB";

  // For larger tests, generate random strings or read from input
  cout << "String A: " << A << "\n";
  cout << "String B: " << B << "\n";

  string lcs = hirschberg(A, B);

  cout << "LCS: " << lcs << "\n"; // Expected: GTAB
  cout << "Length: " << lcs.length() << "\n";

  return 0;
}
