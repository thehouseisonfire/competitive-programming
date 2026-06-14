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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  vector<vector<char>> v(10, vector<char>(10));
  while (t--) {
    cin >> v;
    ll score = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (v[i][j] != 'X')
          continue;
        if (i == 0 || i == 9)
          score++;
        else if ((i == 1 || i == 8)) {
          if (j == 0 || j == 9)
            score++;
          else
            score += 2;
        } else if ((i == 2 || i == 7)) {
          if (j == 0 || j == 9)
            score++;
          else if (j == 1 || j == 8) {
            score += 2;
          } else
            score += 3;
        } else if ((i == 3 || i == 6)) {
          if (j == 0 || j == 9)
            score++;
          else if (j == 1 || j == 8) {
            score += 2;
          } else if (j == 2 || j == 7) {
            score += 3;
          } else
            score += 4;
        } else if ((i == 4 || i == 5)) {
          if (j == 0 || j == 9)
            score++;
          else if (j == 1 || j == 8) {
            score += 2;
          } else if (j == 2 || j == 7) {
            score += 3;
          } else if (j == 3 || j == 6) {
            score += 4;
          } else
            score += 5;
        }
      }
    }
    cout << score << endl;
  }
  return 0;
}
