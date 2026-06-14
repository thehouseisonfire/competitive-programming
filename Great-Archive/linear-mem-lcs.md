### The Linear Space Approach (Hirschberg's Algorithm)
You can reconstruct the LCS using only $O(\min(N, M))$ space (two rows of DP) by using **Hirschberg's Algorithm**.

This is a divide-and-conquer strategy:
1.  Split string $S$ in half.
2.  Calculate the DP values for the first half (forward) and the second half (backward) using only linear space (keeping just the last row).
3.  Find the optimal "split point" $k$ in string $T$ where the sum of `left_len + right_len` is maximized.
4.  Recursively solve for the left part $(S_{0..mid}, T_{0..k})$ and right part $(S_{mid..n}, T_{k..m})$.

**Pros:**
*   Drastically reduces memory from $O(N \cdot M)$ to $O(\min(N, M))$. Critical if $N, M \approx 10^5$.

**Cons:**
*   Slower: It runs in about $2 \times$ the time of the standard DP because it re-computes values.
*   Complex to implement.

### Implementation of Hirschberg's (Linear Space LCS)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

// Standard space-optimized LCS length (returns just the last row)
vector<int> get_lcs_row(const string& s, const string& t) {
    int m = t.size();
    vector<int> dp(m + 1, 0);
    for (char c : s) {
        int prev_diag = 0;
        for (int j = 1; j <= m; ++j) {
            int temp = dp[j];
            if (c == t[j - 1]) {
                dp[j] = prev_diag + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev_diag = temp;
        }
    }
    return dp;
}

string hirschberg(string s, string t) {
    int n = s.size();
    int m = t.size();

    // Base cases
    if (n == 0) return "";
    if (n == 1) {
        if (t.find(s[0]) != string::npos) return s;
        return "";
    }

    // Divide
    int mid = n / 2;
    string s1 = s.substr(0, mid);
    string s2 = s.substr(mid);

    // Get DP rows
    vector<int> L1 = get_lcs_row(s1, t);
    
    // For the second half, we reverse strings to do DP backwards
    string s2_rev = s2; reverse(s2_rev.begin(), s2_rev.end());
    string t_rev = t;   reverse(t_rev.begin(), t_rev.end());
    vector<int> L2 = get_lcs_row(s2_rev, t_rev);

    // Find split point k
    int best_k = 0;
    int max_val = -1;
    for (int k = 0; k <= m; ++k) {
        // L1[k] is LCS of s1 and t[0...k]
        // L2[m-k] is LCS of s2 and t[k...m] (indices aligned due to reverse)
        if (L1[k] + L2[m - k] > max_val) {
            max_val = L1[k] + L2[m - k];
            best_k = k;
        }
    }

    // Conquer
    return hirschberg(s1, t.substr(0, best_k)) + 
           hirschberg(s2, t.substr(best_k));
}

void solve() {
    string s, t;
    cin >> s >> t;
    cout << hirschberg(s, t) << endl;
}

int main() {
    solve();
    return 0;
}
```
