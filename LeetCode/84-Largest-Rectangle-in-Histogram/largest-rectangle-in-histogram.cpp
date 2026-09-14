#include <cmath>
#include <iostream>
#include <stack>
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

class Solution {
public:
  int largestRectangleArea(vector<int> &v) {
    v.push_back(0);
    ll ans = 0;
    stack<ll> st;
    for (ll i = 0; i < v.size() + 1; i++) {
      while (!st.empty() && v[i] <= v[st.top()]) {
        const auto height = v[st.top()];
        st.pop();
        const ll left = st.empty() ? -1 : st.top();
        ans = max(ans, (i - 1 - left) * height);
      }
      st.push(i);
    }
    return ans;
  }
};
