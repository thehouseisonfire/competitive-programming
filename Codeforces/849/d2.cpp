#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v)
    is >> x;
  return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size(); ++i)
    os << (i > 0 ? " " : "") << v[i];
  return os;
}

#define dbg(x) cerr << #x << " = " << (x) << endl
#define all(x) (x).begin(), (x).end()

void solve() {
  ll n;
  cin >> n;
  string v;
  cin >> v;

  int cnt[256] = {0}; // Single array: tracks right-side frequencies

  // Initialize right side with all characters
  int unique_right = 0;
  for (char c : v) {
    if (cnt[c]++ == 0)
      unique_right++;
  }

  int unique_left = 0;
  int max_unique = unique_right;

  for (char c : v) {
    // Move character from right to left
    if (--cnt[c] == 0)
      unique_right--; // Removed last occurrence from right
    if (cnt[c] == 0)
      unique_left++; // Added first occurrence to left (cnt[c] becomes -1, -2,
                     // etc.)
    cnt[c]--;        // Continue tracking on left side

    max_unique = max(max_unique, unique_left + unique_right);
  }

  cout << max_unique << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
