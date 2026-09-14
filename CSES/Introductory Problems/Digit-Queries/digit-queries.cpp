#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll getdigit(ll num, ll n) {
  ll r;
  r = num / (ll)pow(10, n);
  r %= 10;
  return r;
}

ll solution(ll n) {
  if (n < 10) {
    return n;
  }

  ll num_digits = 1;
  ll adder = 9;
  ll compare = n;
  ll i = 0;

  while (true) {
    if (i > compare)
      break;

    i += adder;
    n += (ll)pow(10, num_digits - 1);

    adder = (ll)9 * (ll)pow(10, num_digits) * (num_digits + 1);
    num_digits += 1;
  }

  n -= 1;
  num_digits -= 1;

  ll which_digit = n % num_digits;
  n /= num_digits;

  return getdigit(n, num_digits - 1 - which_digit);
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    ll aux;
    cin >> aux;
    cout << solution(aux) << endl;
  }
}
