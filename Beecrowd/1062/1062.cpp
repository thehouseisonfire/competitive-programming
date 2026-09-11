#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
  while (1) {
    int n;
    cin >> n;
    if (!n)
      return 0;

    while (1) {
      int m, counter = 1;
      bool flag = false;
      stack<int> st;
      vector<int> vec;
      vec.reserve(50);
      st.push(0);
      cin >> m;
      if (!m) {
        cout << endl;
        break;
      }
      vec.push_back(m);
      for (int i = 1; i < n; i++) {
        cin >> m;
        vec.push_back(m);
      }

      for (auto num : vec) {
        while (st.top() < num) {
          st.push(counter);
          counter++;
        }
        if (st.top() == num)
          st.pop();
        else {
          flag = true;
          break;
        }
      }
      flag ? cout << "No\n" : cout << "Yes\n";
    }
  }
}
