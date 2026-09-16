#include <iostream>
#include <vector>

using namespace std;

int solution(const int num, const vector<int> &choices, vector<int> &results) {
  if (num < 0)
    return 1000000;
  if (num == 0)
    return 0;
  if (results[num] != -1)
    return results[num];
  int res = -1;
  int choice1 = 1, choice2 = 2;
  if (num > choices[choices.size() - 1]) {
    res = 1 + solution(num - choices[choices.size() - 1], choices, results);
    results[num] = res;
    return res;
  }
  for (size_t i = 1; i < choices.size(); i++)
    if (choices[i - 1] < num && num <= choices[i])
      choice1 = choices[i - 1], choice2 = choices[i];

  res = 1 + min(solution(num - choice1, choices, results),
                solution(choice2 - num, choices, results));

  results[num] = res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.flush();
  cout.tie(NULL);
  vector<int> v = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
  vector<int> r(2049, -1);
  r[0] = 0;
  r[1] = 1;
  r[2] = 1;
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    cout << solution(m, v, r) << endl;
  }
  return 0;
}
