#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int main() {
  while (1) {
    int n;
    string str;
    str.reserve(51);
    vector<char> in;
    vector<char> out;
    in.reserve(25);
    out.reserve(25);
    cin >> n;
    if (!n)
      return 0;
    for (int i = 0; i < n; i++) {
      char aux;
      cin >> aux;
      in.push_back(aux);
    }
    for (int i = 0; i < n; i++) {
      char aux;
      cin >> aux;
      out.push_back(aux);
    }
    int counter = 0;
    stack<char> st;
    st.push('0');
    for (auto c : out) {
      while (st.top() != c && counter < in.size()) {
        st.push(in[counter]);
        counter++;
        cout << 'I';
      }
      if (st.top() == c) {
        st.pop();
        cout << 'R';
      } else {
        cout << " Impossible";
        break;
      }
    }
    cout << endl;
  }
}
