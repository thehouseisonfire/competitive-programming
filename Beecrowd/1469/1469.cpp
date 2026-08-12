#include <iostream>
#include <list>
#include <vector>
#define INT32_MAX 2000000
using namespace std;

void BFS(int v, const vector<vector<bool>> &mtx, const vector<int> &age,
         vector<int> &results) {
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
      results[i] = INT32_MAX;
  }
}
int main(int argc, char *argv[]) {
  int n, m, k;
  while (cin >> n >> m >> k) {
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
        const auto aux = mtx[v];
        mtx[v] = mtx[w];
        mtx[w] = aux;
        for (int i = 0; i < n; i++) {
          if (mtx[i][v] + mtx[i][w] == 1)
            mtx[i][v] = !mtx[i][v], mtx[i][w] = !mtx[i][w];
        }
      }
      if (c == 'P') {
        int v;
        cin >> v;
        v -= 1;
        vector<int> results(n, 0);
        BFS(v, mtx, age, results);
        results[v] = INT32_MAX;
        int min = results[0];
        for (const auto &pos : results) {
          if (pos < min)
            min = pos;
        }
        if (min == INT32_MAX)
          cout << '*' << endl;
        else
          cout << min << endl;
      }
    }
  }
  return 0;
}
