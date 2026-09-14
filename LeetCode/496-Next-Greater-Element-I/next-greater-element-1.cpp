#include <cmath>
#include <iostream>
#include <map>
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
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    ll n, m;
    cin >> n >> m;
    vll v(n);
    stack<ll> st;
    map<ll, ll> mp;
    cin >> v;
    for (ll i = 0; i < m; i++) {
      ll aux;
      cin >> aux;
      mp[aux] = -1;
      while (!st.empty() && aux > st.top()) {
        const auto top = st.top();
        st.pop();
        mp[top] = aux;
      }
      st.push(aux);
    }
    vector<int> res;
    for (const auto &pos : v)
      res.push_back(mp[pos]);
    return res;
  }
};
