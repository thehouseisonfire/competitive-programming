#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

  ll n;
  cin >> n;
  vector<ll> c(n), k(n);
  for (auto &p : c)
    cin >> p;
  for (auto &p : k)
    cin >> p;

  ll sum = 0;
  for (auto &p : c)
    sum += p;

  ll mindiff = 0;
  for (ll i = 0; i < n; i++) {
    ll diff = c[i] - k[i];
    if (diff < 0) {
      cout << -1 << endl;
      return 0;
    }
    mindiff = min(mindiff, diff);
  }
  sum -= mindiff;

  cout << sum << endl;
  return 0;
}
