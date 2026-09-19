#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  unordered_map<int, int> map;
  for (int i = 0; i < n; i++) {
    int aux;
    cin >> aux;
    map[aux] = i;
    v[i] = aux;
  }
  int count = 1;
  for (int i = 2; i <= n; i++) {
    count += (map[i - 1] > map[i]);
  }
  // cout << count << endl;
  while (m--) {
    int a, b;
    cin >> a >> b;
    int ra = v[a - 1];
    int rb = v[b - 1];

    set<int> dedup = {ra - 1, ra, rb - 1, rb};
    for (const auto &pos : dedup)
      if (pos > 0 && pos < n)
        count -= (map[pos] > map[pos + 1]);

    swap(map[ra], map[rb]);
    swap(v[a - 1], v[b - 1]);

    for (const auto &pos : dedup)
      if (pos > 0 && pos < n)
        count += (map[pos] > map[pos + 1]);
    cout << count << endl;
  }

  return 0;
}
