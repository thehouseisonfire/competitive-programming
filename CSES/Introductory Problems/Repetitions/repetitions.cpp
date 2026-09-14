#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  char prev = ' ';
  int best = 1, local = 1;
  string s;
  cin >> s;
  for (const auto &c : s)
    if (c == prev)
      local++, best = max(best, local);
    else
      prev = c, local = 1;
  cout << best << endl;
  return 0;
}
