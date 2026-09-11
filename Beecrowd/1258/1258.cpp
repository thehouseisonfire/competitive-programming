#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#define u16 short unsigned

using namespace std;

struct Shirt {
  string name;
  char size;
  bool sec_color; // branco = 0; vermelho = 1;
};

bool cmp(const Shirt &l, const Shirt &r) {
  if (l.sec_color != r.sec_color)
    return l.sec_color < r.sec_color;
  if (l.size != r.size) {
    if (l.size == 'G')
      return false;
    else if (r.size == 'G')
      return true;
    else
      return l.size != 'M';
  }
  const auto cmp = l.name.compare(r.name);
  if (cmp)
    return cmp < 0;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  bool flag = false;
  while (cin >> n) {
    cin.ignore();
    if (!n)
      return 0;
    if (flag)
      cout << endl;
    flag = true;
    vector<Shirt> vec;
    vec.reserve(63);
    while (n--) {
      string aux;
      Shirt s;
      getline(cin, s.name);
      getline(cin, aux);
      size_t pos = aux.find(' ');
      if (aux.substr(0, pos) == "vermelho") {
        s.sec_color = 1;
      } else
        s.sec_color = 0;
      string size = aux.substr(pos + 1 /*, aux.end()*/);
      if (size != "P" && size != "M" && size != "G")
        return 1;
      s.size = size.front();
      vec.push_back(s);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto s : vec) {
      cout << (s.sec_color ? "vermelho" : "branco") << " " << s.size << " "
           << s.name << endl;
    }
  }
  return 0;
}
