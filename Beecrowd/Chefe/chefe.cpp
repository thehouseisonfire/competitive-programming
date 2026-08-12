#include <iostream>
#include <list>
#include <vector>

using namespace std;

void BFS(int v, const vector<vector<bool>> &mtx, const vector<int> &age,
         vector<int> &results) {
  cout << endl;
  vector<bool> visited(mtx.size(), 0);
  list<int> queue;

  visited[v] = 1;
  queue.push_back(v);

  while (!queue.empty()) {

    v = queue.front();
    queue.pop_front();

    for (int i = 0; i < mtx[v].size(); i++) {
      if (mtx[v][i] == true && !visited[i]) {
        queue.push_back(i);
        visited[i] = 1;
      }
    }
  }
  for (int i = 0; i < mtx.size(); i++) {
    if (visited[i])
      results[i] = age[i];
    else
      results[i] = 2000000000;
  }
  // for (const auto &pos : results) {
  //   cout << pos << " ";
  // }
  // cout << endl;
}
int main(int argc, char *argv[]) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> age(n);
  vector<vector<bool>> mtx(n, vector<bool>(n, 0));
  for (auto &pos : age)
    cin >> pos;
  while (m--) {
    int v, w;
    cin >> v >> w;
    mtx[w - 1][v - 1] = 1;
  }
  while (k--) {
    char c;
    cin >> c;
    if (c == 'T') {
      int v, w;
      cin >> v >> w;
      v -= 1;
      w -= 1;
      for (int i = 0; i < n; i++)
        swap(mtx[v][i], mtx[w][i]);
    }
    if (c == 'P') {
      int v;
      cin >> v;
      vector<vector<int>> mtx1(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (mtx[i][j])
            mtx1[i][j] = age[j];
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << mtx1[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      // v -= 1;
      // vector<int> results(n, 0);
      // BFS(v, mtx, age, results);
      // int min = results[0];
      // for (const auto &pos : results)
      //   if (pos < min)
      //     min = pos;
      // cout << min;
    }
  }

  return 0;
}
