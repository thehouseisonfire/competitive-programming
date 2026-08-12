#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct student {
  string name;
  char region;
  int dist;
};

bool cmp(const student &a, const student &b) {
  if (a.dist != b.dist)
    return a.dist < b.dist;
  if (a.region != b.region)
    return a.region < b.region;
  return b.name.compare(a.name) > 0;
};

int main() {
  int n;
  while (cin >> n) {
    vector<student> v;
    while (n--) {
      student st;
      cin >> st.name >> st.region >> st.dist;
      v.push_back(st);
    }
    sort(v.begin(), v.end(), cmp);
    for (const auto &st : v)
      cout << st.name << endl;
  }
  return 0;
}
