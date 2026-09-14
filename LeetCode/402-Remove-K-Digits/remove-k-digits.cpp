#include <algorithm>
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

int solution(int num, const vi &choices, const vi &results);

class Solution {
public:
  string removeKdigits(string s, ll k) {
    stack<char> st;
    for (const auto &pos : s) {
      while (!st.empty() && pos < st.top() && k > 0)
        st.pop(), k--;
      st.push(pos);
    }
    while (k-- && !st.empty())
      st.pop();

    string res;
    while (!st.empty())
      res.push_back(st.top()), st.pop();
    while (res.size() && res[res.size() - 1] == '0')
      res.pop_back();
    reverse(all(res));
    if (!res.size())
      res.push_back('0');

    return res.empty() ? "0" : res;
  }
};
