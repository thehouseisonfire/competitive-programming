#include <iostream>
#include <map>
#include <string>

using namespace std;

int solution();

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string murder, murderer;
  map<string, int> kill_count;
  while (cin >> murder >> murderer) {
    kill_count[murder]++;
    kill_count[murderer] = -100000;
  }
  cout << "HALL OF MURDERERS\n";
  for (auto murderer : kill_count)
    if (murderer.second > 0)
      cout << murderer.first << " " << murderer.second << endl;
  return 0;
}
