#include <iostream>
#include <map>
#include <string>

using namespace std;

int solution();

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // map<char[10], int> kill_count; // doesnt work, giga cringe
  string murder, murderer;
  map<string, int> kill_count;
  while (cin >> murder >> murderer) {
    // could do this 'if' instead of line 21
    // if (kill_count[murder] < 0)
    kill_count[murder]++;
    // works because of the '=< 10^5' input constraint (use -1 otherwise)
    kill_count[murderer] = -100000;
  }
  cout << "HALL OF MURDERERS\n";
  for (auto murderer : kill_count)
    if (murderer.second > 0)
      cout << murderer.first << " " << murderer.second << endl;
  return 0;
}
