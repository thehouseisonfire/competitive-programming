#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

using ll = int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;
// const ll INF = 1e18;
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

const int LOG = 31;
static int up[200000][LOG];

ll kth_ancestor(ll v, ll k) {
  for (ll i = 0; i < LOG; i++) {
    if ((1 << i) & k) {
      v = up[v][i];
      if (v == -1)
        return -1;
    }
  }
  return v;
}

void solve() {
  ll n, q;
  cin >> n >> q;
  for (ll i = 0; i < n; i++) {
    cin >> up[i][0];
    up[i][0]--;
  }
  for (ll j = 1; j < LOG; j++) {
    for (ll i = 0; i < n; i++) {
      ll mid = up[i][j - 1];
      if (mid != -1)
        up[i][j] = up[mid][j - 1];
    }
  }
  while (q--) {
    int a, k;
    cin >> a >> k;
    a--;
    cout << kth_ancestor(a, k) + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
