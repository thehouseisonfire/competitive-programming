#include <algorithm>
#include <iostream>
#include <vector>

#define pi pair<int, int>

using namespace std;
vector<int> r;
int solution(const int num, const pi &choices, const vector<int> &holes,
             vector<int> &results) {

  if (num >= *(holes.end() - 1))
    return 0;

  if (results[num] != -1)
    return results[num];

  const int upper = *upper_bound(holes.cbegin(), holes.cend(), num);
  const int mini = min(
      choices.first + solution(upper + choices.first, choices, holes, results),
      choices.second +
          solution(upper + choices.second, choices, holes, results));
  results[num] = mini;
  return mini;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  pi choices;
  while (cin >> n >> c >> choices.first >> choices.second && n != 0) {
    vector<int> holes(n);

    for (auto &pos : holes)
      cin >> pos;

    sort(holes.begin(), holes.end());
    r.clear();
    r.resize(c);
    fill(r.begin(), r.end(), -1);

    cout << solution(0, choices, holes, r) << endl;
  }
  return 0;
}
