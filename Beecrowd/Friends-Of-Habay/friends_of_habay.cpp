#include <iostream>
#include <set>

using namespace std;

// int main(int argc, char *argv[]) {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
//
//   string name, winner;
//   set<string> potencial_friends;
//   cin >> name;
//   while (name != "FIM") {
//     string answer;
//     cin >> answer;
//     if (answer == "YES") {
//       potencial_friends.insert(name);
//       if (name.length() > winner.length())
//         winner = name;
//     }
// else
//   not_friends.insert(name);
//     cin >> name;
//   }
//   for (string name : potencial_friends) {
//     cout << name << endl;
//   }
// for (string name : not_friends) {
//   cout << name << endl;
// }
//   cout << "\nAmigo do Habay:\n" << winner << endl;
//   return 0;
// }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string name, answer, winner;
  set<string> potencial_friends, not_friends;
  while (cin >> name >> answer) {
    if (answer == "YES") {
      potencial_friends.insert(name);
      if (name.length() > winner.length())
        winner = name;
    } else
      not_friends.insert(name);
  }
  for (string name : potencial_friends) {
    cout << name << endl;
  }
  for (string name : not_friends) {
    cout << name << endl;
  }
  cout << "\nAmigo do Habay:\n" << winner << endl;
  return 0;
}
