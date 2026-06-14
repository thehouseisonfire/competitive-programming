#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isBipartiteUtil(vector<vector<int>> G, int src, int *colorArr,
                     int m_size) {
  colorArr[src] = 1;

  // Create a queue (FIFO) of vertex numbers a
  // nd enqueue source vertex for BFS traversal
  queue<int> q;
  q.push(src);

  // Run while there are vertices in queue (Similar to
  // BFS)
  while (!q.empty()) {
    // Dequeue a vertex from queue ( Refer
    // http://goo.gl/35oz8 )
    int u = q.front();
    q.pop();

    // Return false if there is a self-loop
    if (G[u][u] == 1)
      return false;

    // Find all non-colored adjacent vertices
    for (int v = 0; v < m_size; ++v) {
      // An edge from u to v exists and
      // destination v is not colored
      if (G[u][v] && colorArr[v] == -1) {
        // Assign alternate color to this
        // adjacent v of u
        colorArr[v] = 1 - colorArr[u];
        q.push(v);
      }

      // An edge from u to v exists and destination
      // v is colored with same color as u
      else if (G[u][v] && colorArr[v] == colorArr[u])
        return false;
    }
  }

  // If we reach here, then all adjacent vertices can
  // be colored with alternate color
  return true;
  cout << endl;
  for (int i = 0; i < m_size; i++) {
    cout << colorArr[i] << " ";
  }
  // If we reach here, then all adjacent
  // vertices can be colored with alternate color
  return true;
}
bool isBipartite(vector<vector<int>> G, int m_size) {
  int colorArr[m_size];
  for (int i = 0; i < m_size; ++i)
    colorArr[i] = -1;

  // This code is to handle disconnected graph
  for (int i = 0; i < m_size; i++)
    if (colorArr[i] == -1)
      if (isBipartiteUtil(G, i, colorArr, m_size) == false)
        return false;

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
      // if (i != j)
      //   aux = !aux;
      arr[i][j] = !aux;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  isBipartite(arr, n) ? cout << "\nBazinga!\n" : cout << "\nfail!\n";
  return 0;
}
