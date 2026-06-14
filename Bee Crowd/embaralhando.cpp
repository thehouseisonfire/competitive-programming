#include <iostream>
#include <unordered_map>
#include <vector>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

using namespace std;

// 1 2
// 2 1
// 1 2
//
// 1 2 3 4 - 2 1 3 4 -
// 3 1 4 2
// 4 3 2 1
// 2 4 1 3
// 1 2 3 4
//
// 1 2 3 4 5 6
// 4 1 5 2 6 3
// 2 4 6 1 3 5
// 1 2 3 4 5 6

bool sorted(const vector<int> &v) {
  for (int i = 1; i < v.size(); i++)
    if (v[i - 1] > v[i])
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int len, count = 1;
  vector<int> v;
  cin >> len;
  v.reserve(len);
  const int half = len >> 1;
  for (int i = 1; i <= half; i++) {
    v.push_back(half + i);
    v.push_back(i);
  }
  while (!sorted(v)) {
    const vector<int> w(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i < len; i += 2) {
      v[i] = w[half + j];
      v[i + 1] = w[j];
      j++;
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
