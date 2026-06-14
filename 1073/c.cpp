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

// se o numero de moviementos for menor que a soma das possicoes.
// se, apos a posicao normalizada, a distnacia manhattan for impar.

const ll MAX_N = 2 * 1e5 + 5;

string s;
vector<pll> prefix(MAX_N);

bool check(ll i, ll j, ll sum) { return sum & 1 && (j - i) * 2 > sum; }

void solve() {
  ll n;
  cin >> n;
  cout << MAX_N << endl;
  cin >> s;
  pll dist;
  cin >> dist.first >> dist.second;

  pll sum = {};
  for (ll i = 0; i < n; i++) {
    const auto pos = s[i];
    if (pos == 'U')
      sum.first++;
    if (pos == 'D')
      sum.first--;
    if (pos == 'R')
      sum.second++;
    if (pos == 'L')
      sum.second--;
    prefix[i] = sum;
  }
  ll i = 0, j = 1;
  while (i < j) {
    const pll curr = {prefix[i].first - prefix[0].first + prefix[n - 1].first -
                          prefix[j].first,
                      prefix[i].second - prefix[0].second +
                          prefix[n - 1].second - prefix[j].second};

    const auto [target_v, target_h] =
        pll{dist.first - curr.first, dist.second - curr.second};
    ll sum = target_v + target_h;
    if (sum % 2 == 0 && (j - i) << 1 > sum) {
    }
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
