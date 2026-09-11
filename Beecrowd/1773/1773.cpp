#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {

  int size, edges;
  while (cin >> size >> edges) {
    vector<vector<int>> v(size);
    int i = edges;
    while (i--) {
      int w, u;
      cin >> w >> u;
      w--, u--;
      v[u].push_back(w);
      v[w].push_back(u);
    }

    vector<bool> visited(size, false);
    map<int, int> locations;
    set<int> found;

    for (int i = 1; i < size; i++) {
      int a;
      cin >> a;
      locations[a - 1] = i;
    }
    // for (const auto [a, b] : locations) {
    //   cout << a << " " << b << endl;
    // }

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      found.insert(locations[u]);

      for (const auto &neighbor : v[u])
        if (!visited[neighbor] && found.count(neighbor))
          visited[neighbor] = true, q.push(neighbor);
    }
    bool flag = true;
    for (const auto &pos : visited)
      if (!pos)
        flag = false;
    cout << (flag ? "sim" : "nao") << endl;
  }
  return 0;
}
