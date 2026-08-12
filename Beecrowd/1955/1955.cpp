#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> &G, const int src, const int m_size) {
  int colorArr[m_size];
  for (int i = 0; i < m_size; ++i)
    colorArr[i] = -1;
  colorArr[src] = 1;

  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v < m_size; ++v) {
      if (G[u][v] && colorArr[v] == -1) {
        colorArr[v] = 1 - colorArr[u];
        q.push(v);
      }

      else if (G[u][v] && colorArr[v] == colorArr[u])
        return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int aux;
      cin >> aux;
      arr[i][j] = !aux;
    }
  }
  solution(arr, 0, n) ? cout << "Bazinga!\n" : cout << "Fail!\n";
  return 0;
}
