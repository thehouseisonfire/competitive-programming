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

int solution(int num, const vi &choices, const vi &results);

void solve() {
  ll n;
  char st;
  cin >> n >> st;
  string s;
  cin >> s;
  s += s;
  ll save = -1;
  vll dist(n);
  for (ll i = 0; i < (n << 1); i++) {
    if (!(s[i] == 'g'))
      continue;
    for (ll j = i - 1; j > save; j--) {
      if (j >= n)
        continue;
      dist[j] = i - j;
    }
    save = i;
  }
  ll worst = 0;
  for (ll i = 0; i < n; i++) {
    if (st == 'r' && s[i] == 'r')
      worst = max(worst, dist[i]);
    if (st == 'y' && s[i] == 'y')
      worst = max(worst, dist[i]);
  }
  cout << worst << endl;
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
