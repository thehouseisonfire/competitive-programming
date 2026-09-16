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

const int mod = 1e9 + 7;
const ll inf = 1e18;
const ld pi = acos(-1.0);

template <typename t1, typename t2>
istream &operator>>(istream &is, pair<t1, t2> &p) {
  return is >> p.first >> p.second;
}
template <typename t1, typename t2>
ostream &operator<<(ostream &os, const pair<t1, t2> &p) {
  return os << p.first << " " << p.second;
}

template <typename t> istream &operator>>(istream &is, vector<t> &v) {
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

long long countAndMerge(vector<string> &arr, ll l, ll m, ll r) {
  ll n1 = m - l + 1, n2 = r - m;

  vector<string> left(n1), right(n2);
  for (ll i = 0; i < n1; i++)
    left[i] = arr[i + l];
  for (ll j = 0; j < n2; j++)
    right[j] = arr[m + 1 + j];

  long long res = 0;
  ll i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {

    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
      res += (n1 - i);
    }
  }

  while (i < n1)
    arr[k++] = left[i++];
  while (j < n2)
    arr[k++] = right[j++];

  return res;
}

long long countInv(vector<string> &arr, ll l, ll r) {
  long long res = 0;
  if (l < r) {
    ll m = (r + l) / 2;

    res += countInv(arr, l, m);
    res += countInv(arr, m + 1, r);

    res += countAndMerge(arr, l, m, r);
  }
  return res;
}

int main() {
  ll n;
  while (cin >> n) {
    vector<string> v(n);
    cin >> v;
    cout << countInv(v, 0, n - 1) << endl;
  }
  return 0;
}
