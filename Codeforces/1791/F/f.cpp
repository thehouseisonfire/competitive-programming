#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
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

const int MAXN = 200005;

int fn(int x) {
  int sum = 0;

  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

const int N = 2 * 1e5;
long t[2 * N];
int n;

void build() {
  for (int i = 0; i < n * 2; i++)
    t[i] = 0;
}

void rangeUpdate(int l, int r, long value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      t[l++] += value;
    if (r & 1)
      t[--r] += value;
  }
}

long query(int p) {
  long asw = 0;
  for (p += n; p > 0; p >>= 1)
    asw += t[p];
  return asw;
}

void solve() {
  int q;
  cin >> n >> q;
  vi v(n);
  cin >> v;

  build();
  for (int i = 0; i < q; i++) {
    int x, y, z;
    cin >> x >> y;
    if (x == 2) {
      int times = min(query(y - 1), 4l);
      ll res = v[y - 1];
      while (times--)
        res = fn(res);
      cout << res << endl;
    } else {
      cin >> z;
      rangeUpdate(y - 1, z, 1);
    }
  }
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
