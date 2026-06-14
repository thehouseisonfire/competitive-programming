#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;
  vector<array<ll, 3>> v(n);
  priority_queue<ll, vector<ll>, greater<ll>> goback;
  priority_queue<ll, vector<ll>, greater<ll>> comeback;

  for (ll i = 0; i < n; ++i) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }

  sort(v.begin(), v.end());

  ll mars = 2;
  ll earth = 0;
  ll count = 0;
  for (const auto &[l, r, t] : v) {

    while (!comeback.empty() && comeback.top() <= l)
      comeback.pop(), mars++;

    while (!goback.empty() && goback.top() <= l)
      goback.pop(), earth++;

    if (!t) {
      if (mars)
        goback.push(r), mars--;
    } else if (earth)
      comeback.push(r), earth--, count++;
  }

  cout << count << endl;
  return 0;
}
