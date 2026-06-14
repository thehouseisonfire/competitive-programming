// lowest common subsequence

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  while (cin >> N) {
    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
      cin >> nums[i];

    vector<int> lis;

    for (int i = 0; i < N; ++i) {
      auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
      if (it == lis.end()) {
        lis.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }

    cout << lis.size() << endl;
  }

  return 0;
}
