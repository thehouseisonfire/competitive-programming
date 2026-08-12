#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>
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

vll parent;
vll sizes;
void make_set(ll v) {
  parent[v] = v;
  sizes[v] = 1;
}

ll find_set(ll v) {
  if (v == parent[v])
    return v;
  return parent[v] == find_set(parent[v]);
}

// returns false if no sets were joined.
bool join_sets2(ll a, ll b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b)
    return 0;
  if (sizes[a] > sizes[b])
    swap(a, b);
  parent[a] = b;
  sizes[b] += sizes[a];
  return 1;
}

void solve() {
  ll n, m;
  cin >> n;
  parent.resize(n);
  for (ll i = 0; i < n; i++)
    parent[i] = i;

  vector<pair<ll, pair<ll, pll>>> v(m);
  for (ll i = 0; i < m; i++) {
    auto pos = v[i];
    cin >> pos.second.second.first >> pos.second.second.second >> pos.first >>
        pos.second.first;
  }

  sort(all(v));
  map<pll, bool> mapa, temp_mapa;
  ll last_w = v[0].first;
  for (const auto &[w, vs] : v) {
    const auto [_, ps] = vs;
    const auto [a, b] = ps;
    if (last_w != w) {
      for (const auto &[pos, _] : temp_mapa)
        join_sets2(pos.first, pos.second);
      mapa.merge(temp_mapa);
      temp_mapa.clear();
    } else {
      temp_mapa[{a, b}] = find_set(a) != find_set(b);
    }
    last_w = w;
  }
  for (auto &[w, vs] : v) {
    swap(w, vs.first);
  }
  sort(all(v));
  for (const auto &[_, vs] : v) {
    cout << (mapa[{vs.second.first, vs.second.second}] ? "YES" : "NO") << endl;
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
