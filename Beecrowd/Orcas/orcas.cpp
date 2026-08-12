#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> &G, const int src, const int m_size) {
  // Create a color array to store colors
  // assigned to all vertices. m_sizeertex
  // number is used as index in this array.
  // The value '-1' of colorArr[i]
  // is used to indicate that no color
  // is assigned to vertex 'i'. The value 1
  // is used to indicate first color
  // is assigned and value 0 indicates
  // second color is assigned.
  int colorArr[m_size];
  for (int i = 0; i < m_size; ++i)
    colorArr[i] = -1;

  // Assign first color to source
  colorArr[src] = 1;

  // Create a queue (FIFO) of vertex
  // numbers and enqueue source vertex
  // for BFS traversal
  queue<int> q;
  q.push(src);

  // Run while there are vertices
  // in queue (Similar to BFS)
  while (!q.empty()) {
    // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
    int u = q.front();
    q.pop();

    // // Return false if there is a self-loop
    // if (G[u][u] == 1)
    //   return false;

    // Find all non-colored adjacent vertices
    for (int v = 0; v < m_size; ++v) {
      // An edge from u to v exists and
      // destination v is not colored
      if (G[u][v] && colorArr[v] == -1) {
        // Assign alternate color to this adjacent v of u
        colorArr[v] = 1 - colorArr[u];
        q.push(v);
      }

      // An edge from u to v exists and destination
      // v is colored with same color as u
      else if (G[u][v] && colorArr[v] == colorArr[u])
        return false;
    }
  }
  for (int i = 0; i < m_size; i++) {
    cout << colorArr[i] << " ";
  }
  // If we reach here, then all adjacent
  // vertices can be colored with alternate color
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
  solution(arr, 0, n) ? cout << "\nBazinga!\n" : cout << "\nfail\n";
  return 0;
}
