// regra numero 1:
//
// COLOCA BOUND EXATO. SE O T VAI DE 0 ATE 100, L = 0 E R = 100
//
//
// regra numero 2:
//
// VE SE A STRING TA CERTA ANTES DE MANDAR, PQ VCS VAO DIMINUIR ELA PRA TESTAR E
// SE FERRAR
//
//
// regra numero 3:
//
// 'WRONG ANSWER' EH A MESMA COISA QUE 'TIME LIMIT EXCEDEED' NESSES PROBLEMAS

#include <cmath>
#include <ios>
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

void solve() {
  ll l = 1, r = 1000000000;
  // ll l = 1, r = 100;
  string s;

  while (l < r) {
    ll mid = (l + r) / 2;
    cout << "? " << mid << endl;
    cin >> s;
    if (s == "QUENTE") {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << "! " << r << endl;
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
