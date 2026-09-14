#include <iostream>
#include <set>

int main(int argc, char *argv[]) {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  set<int> s;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    s.insert(m);
  }
  cout << s.size() << endl;
  return 0;
}
