#include <iostream>
#include <numeric>
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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n) {
    string str;
    vector<unsigned> vec;
    str.reserve(10);
    vec.reserve(20);
    cout << "a" << endl;
    while (n--) {
      cin >> str;
      int count = -26;
      for (auto c : str) {
        count += c;
      }
      vec.push_back(count);
    }
    // for (auto i : vec) {
    //   cout << i << endl;
    // }
    // return 0;
    // int i = (vec.size() << 1) - 1;
    // while (true) {
    //   int teamA = 0, teamB = 0;
    //   for (int j = i; j >= 0; j--) {
    //     teamA += vec[j] * (i - j);
    //   }
    //   for (int j = i + 1; j < vec.size(); j++) {
    //     teamB += vec[j] * (j - (i - 1));
    //   }
    //   if (teamA - teamB == 0) {
    //     cout << "YAY, " << i << endl;
    //   }
    //   if (teamA - teamB > 0) {
    //   }
    int l = 0;
    int r = vec.size() - 1;
    while (l <= r) {
      int TeamA = 0, TeamB = 0, multiplier = 1;
      int pivot = l + (r - l) / 2;
      for (int i = pivot; i >= 0; i--) {
        TeamA += vec[i] * multiplier;
        multiplier++;
      }
      multiplier = 1;
      for (int i = pivot + 1; i <= vec.size(); i++) {
        TeamB += vec[i] * multiplier;
        multiplier++;
      }
      if (TeamA - TeamB == 0)
        cout << "YAY, " << pivot;
      if (TeamA - TeamB < 0)
        l = pivot + 1;
      else
        r = pivot - 1;
    }
    // if we reach here, then element was
    // not present
    return -1;
  }

  return 0;
}
