#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define u16 short unsigned

using namespace std;

string extract_ints(ctype_base::mask category, string str,
                    ctype<char> const &facet) {

  char const *begin = &str.front(), *end = &str.back();

  auto res = facet.scan_is(category, begin, end);

  begin = &res[0];
  end = &res[strlen(res)];

  return string(begin, end);
}

string extract_ints(string str) {
  return extract_ints(ctype_base::digit, str,
                      use_facet<ctype<char>>(locale("")));
}

int main() {
  int n;
  string str;
  vector<u16> vec;
  str.reserve(100);
  vec.reserve(100);
  cin >> n;
  while (n--) {
    int m, ignore;
    cin >> ignore;
    cin.ignore();
    getline(cin, str);
    stringstream ss(extract_ints(str));
    while (ss >> m)
      vec.push_back(m);
    sort(vec.begin(), vec.end());
    for (auto i : vec) {
      if (i == vec.back()) {
        n == 1 ? cout << i << " \n" : cout << i << endl;
      } else
        cout << i << " ";
    }
    vec.clear();
  }

  return 0;
}
