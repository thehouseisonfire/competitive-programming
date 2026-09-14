#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int factorial(const int n) {
  if (n < 3)
    return n;
  vector<int> results(n + 1);
  results[2] = 2;
  for (int i = 3; i <= n; i++)
    results[i] = i * results[i - 1];
  return results[n];
}

int formula(const string &str) {
  int alphabet[26] = {0};
  for (char c : str) {
    alphabet[c - 'a']++;
  }
  int result = factorial(str.length());
  int divide = 1;
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] > 1)
      divide *= factorial(alphabet[i]);
  }
  return result / divide;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  str.reserve(69);
  getline(cin, str);
  int ammount = formula(str);
  cout << ammount << endl;
  sort(str.begin(), str.end());
  cout << str << endl;
  ammount--;
  while (ammount--) {
    next_permutation(str.begin(), str.end());
    cout << str << endl;
  }
  return 0;
}
