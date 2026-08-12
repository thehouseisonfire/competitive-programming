#include <iostream>
#include <vector>

using namespace std;

long long calculate_sides(const vector<long long> &numbers, const int m) {
  long long left = 0, right = 0, multiplier = 1;
  for (int i = m; i >= 0; i--) {
    left += numbers[i] * multiplier;
    multiplier++;
  }
  multiplier = 1;
  for (int i = m + 1; i < numbers.size(); i++) {
    right += numbers[i] * multiplier;
    multiplier++;
  }
  return left - right;
}

int main(int argc, char *argv[]) {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 0;
next:
  while (cin >> n) {
    if (!n)
      return 0;
    vector<string> names;
    vector<long long> numbers;
    names.reserve(50);
    numbers.reserve(50);
    int l = 0, r = n - 1, target = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      string str;
      str.reserve(20);
      cin >> str;
      names.push_back(str);
      for (auto c : str)
        sum += c;
      target += sum;
      numbers.push_back(sum);
    }
    while (l <= r) {
      int m = l + (r - l) / 2;
      long long result = calculate_sides(numbers, m);
      if (!result) {
        cout << names[m] << endl;
        goto next;
      } else if (result > 0) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << "Impossibilidade de empate." << endl;
  }
}
