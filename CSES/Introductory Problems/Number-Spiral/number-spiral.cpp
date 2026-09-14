#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solution(ll row, ll col) {
  int flags = ((row < col) << 1) + (max(row, col) % 2 == 0);
  switch (flags) {
  case 0:
    return (row - 1) * (row - 1) + col;
  case 1:
    return row * row + 1 - col;
  case 2:
    return col * col + 1 - row;
  case 3:
    return (col - 1) * (col - 1) + row;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  ll n;
  cin >> n;
  while (n--) {
    ll row, col;
    cin >> row >> col;
    cout << solution(row, col) << endl;
  }
  return 0;
}
