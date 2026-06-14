#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
set<string> ingredients;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str, str2;
    cin >> str >> str2 >> str2;
    ingredients.insert(str);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str, str2;
    cin >> str >> str2 >> str2;
    ingredients.insert(str);
  }
  for (auto str : ingredients) {
    cout << str << endl;
  }
  return 0;
}

// for (int i = 0; i < n; i++) {
//   string str;
//   getline(cin, str);
//   size_t space_pos = str.find(" ");
//   if (space_pos != std::string::npos)
//     str = str.substr(0, space_pos + 1);
//   cout << str << endl;
//   // ingredients.insert(str);
// }
