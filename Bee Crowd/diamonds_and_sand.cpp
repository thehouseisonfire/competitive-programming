#include <iostream>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

using namespace std;

u16 solution(const string str) {
  u16 left = 0;
  u16 diamond = 0;
  for (char c : str) {
    if (c == '<')
      left++;
    else if (c == '>' && left > 0) {
      left--;
      diamond++;
    }
  }
  return diamond;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin >> str;
  cout << solution(str) << endl;
  return 0;
}
