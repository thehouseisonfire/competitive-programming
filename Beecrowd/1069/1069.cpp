#include <iostream>
using namespace std;
#define u16 short unsigned
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
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    cout << solution(str) << endl;
  }
  return 0;
}
