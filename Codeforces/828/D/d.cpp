#include <cmath>
#include <iostream>
#include <queue>
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

const ll MAX = 1000000;

vll arr(MAX);

void pre() {
  for (ll i = 0; i < MAX; i++) {
    ll aux = i;
    while (aux > 1 && aux % 2 == 0) {
      aux /= 2;
      arr[i]++;
    }
  }
}

void solve() {
  ll n, count = 0;
  cin >> n;
  vll v(n);
  cin >> v;

  ll target = n;
  for (ll i = 0; i < n; i++) {
    while (v[i] > 1 && v[i] % 2 == 0) {
      target--;
      v[i] /= 2;
    }
  }
  if (0 >= target) {
    cout << 0 << endl;
    return;
  }

  priority_queue<ll> pq;
  for (ll i = 2; i <= n; i += 2) {
    pq.push(arr[i]);
  }

  while (target > 0 && !pq.empty()) {
    count++;
    target -= pq.top();
    pq.pop();
  }

  if (0 < target) {
    cout << -1 << endl;
    return;
  }
  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
