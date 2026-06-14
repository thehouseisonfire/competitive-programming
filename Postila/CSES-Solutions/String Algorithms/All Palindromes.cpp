#include <bits/stdc++.h>
using namespace std;

struct Node {
  int len;             // length of palindrome
  int link;            // suffix link
  array<int, 26> next; // transitions by char
  Node(int l = 0) : len(l), link(0) { next.fill(-1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  if (!(cin >> s))
    return 0;
  int n = (int)s.size();

  vector<Node> tree;
  tree.reserve(n + 5);
  tree.emplace_back(-1); // node 0: length -1 (imaginary)
  tree.emplace_back(0);  // node 1: length 0 (empty)
  tree[0].link = 0;
  tree[1].link = 0;

  int last = 1; // index of node representing longest suffix-palindrome so far
  vector<int> ans(n);

  for (int pos = 0; pos < n; ++pos) {
    int c = s[pos] - 'a';
    int cur = last;
    // find largest suffix-palindrome of the current processed prefix that can
    // be extended
    while (true) {
      int curlen = tree[cur].len;
      if (pos - curlen - 1 >= 0 && s[pos - curlen - 1] == s[pos])
        break;
      cur = tree[cur].link;
    }

    if (tree[cur].next[c] != -1) {
      // palindrome already exists
      last = tree[cur].next[c];
    } else {
      // create new node
      int newIdx = (int)tree.size();
      tree.emplace_back(tree[cur].len + 2);
      tree[cur].next[c] = newIdx;

      if (tree[newIdx].len == 1) {
        // single character palindrome -> link to empty palindrome node
        tree[newIdx].link = 1;
      } else {
        // find suffix link for the new node
        int tmp = tree[cur].link;
        while (true) {
          int tmplen = tree[tmp].len;
          if (pos - tmplen - 1 >= 0 && s[pos - tmplen - 1] == s[pos])
            break;
          tmp = tree[tmp].link;
        }
        tree[newIdx].link = tree[tmp].next[c];
      }
      last = newIdx;
    }

    ans[pos] = tree[last].len;
  }

  for (int i = 0; i < n; ++i) {
    if (i)
      cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
