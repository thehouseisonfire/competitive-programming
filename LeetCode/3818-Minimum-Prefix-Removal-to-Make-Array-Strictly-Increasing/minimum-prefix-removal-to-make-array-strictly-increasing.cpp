#include <vector>

class Solution {
public:
  int minimumPrefixLength(std::vector<int> &v) {
    int buffer_idx = 0;
    for (int i = 1; i < v.size(); i++) {
      if (v[i] <= v[i - 1]) {
        while (buffer_idx < i)
          buffer_idx++;
      }
    }
    return buffer_idx;
  }
};
