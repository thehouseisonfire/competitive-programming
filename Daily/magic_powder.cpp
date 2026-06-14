#include <algorithm>
#include <cmath>
#include <functional>
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

using plll = pair<ll, pll>;

void solve() {
  ll n, k;
  cin >> n >> k;
  vll weights(n), ingredients(n);
  priority_queue<plll, vector<plll>, std::greater<>> pq;
  cin >> weights >> ingredients;
  if (n == 1) {
    cout << (ingredients[0] + k) / weights[0] << endl;
  }
  for (int i = 0; i < n; i++) {
    pq.push({ingredients[i] / weights[i],
             {weights[i], ingredients[i] % weights[i]}});
  }
  while (k > 0) {
    auto [amount, meta] = pq.top();
    const auto [weight, rem] = meta;
    pq.pop();
    ll target = pq.top().first + 1 - amount;

    target = target * weight;
    target = min(target, k + rem);
    k -= (target - rem);
    amount += target / weight;
    pq.push({amount, {weight, 0}});
  }
  cout << pq.top().first << endl;
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
