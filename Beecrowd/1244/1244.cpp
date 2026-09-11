#include <algorithm>
#include <iostream>
#include <vector>
#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) fixed << setprecision(1) << (x)

using namespace std;

bool compare(const string &a, const string &b) { return a.size() > b.size(); }

int main() {
  int n;
  string str;
  vector<string> vec;
  str.reserve(200);
  vec.reserve(50);
  cin >> n;
  cin.ignore();
  while (n--) {
    getline(cin, str);
    string word = "";
    char prev = -1;
    for (int i = 0; i < str.length(); i++) {
      if (i == str.length() - 1) {
        if (str[i] != ' ')
          word += str[i];
        vec.push_back(word);
        break;
      }
      if (prev == ' ' && str[i] == ' ')
        continue;
      if (prev == ' ' && str[i] != ' ')
        word += str[i];
      if (prev != ' ' && str[i] == ' ') {
        vec.push_back(word);
        word = "";
      }
      if (prev != ' ' && str[i] != ' ')
        word += str[i];
      prev = str[i];
    }
    stable_sort(vec.begin(), vec.end(), compare);
    // for (auto s : vec) {
    //   cout << s << " ";
    // }
    // cout << endl;
    for (int i = 0; i < vec.size(); i++) {
      i == vec.size() - 1 ? cout << vec[i] << endl : cout << vec[i] << " ";
    }
    vec.clear();
  }

  return 0;
}
