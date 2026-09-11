#include <iostream>
#include <unordered_map>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long unsigned n;
  while (cin >> n) {
    if (!n)
      return 0;
    unordered_map<long long unsigned, bool> map;
    for (int i = 0; i < n; i++) {
      long long unsigned num;
      cin >> num;
      map[num] = !map[num];
    }
    for (auto pair : map) {
      if (pair.second) {
        cout << pair.first << endl;
        break;
      }
    }
  }
  return 0;
}
