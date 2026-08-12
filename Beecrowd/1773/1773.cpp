#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <thread>
#include <vector>

using namespace std;

struct Edge {
  int u, v, weight;
};

class Graph {
  int V;
  vector<vector<pair<int, int>>> adj;

public:
  Graph(int V) : V(V) { adj.resize(V); }

  void addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  void DFSUtil(int v, vector<bool> &visited) {
    visited[v] = true;

    for (auto &neighbor : adj[v]) {
      int u = neighbor.first;
      if (!visited[u])
        DFSUtil(u, visited);
    }
  }

  bool DFS(int v) {
    vector<bool> visited(V, false);
    DFSUtil(v, visited);
    for (const auto &pos : visited)
      if (!pos)
        return false;
    return true;
  }

  void BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
      int v = q.front();
      q.pop();
      // cout << v << " ";

      for (const auto &neighbor : adj[v]) {
        int u = neighbor.first;
        if (!visited[u]) {
          visited[u] = true;
          q.push(u);
        }
      }
    }
  }

  int kruskalMST() {
    vector<Edge> edges;
    vector<pair<int, int>> result;

    for (int u = 0; u < V; ++u) {
      for (auto &neighbor : adj[u]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        edges.push_back({u, v, weight});
      }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

    vector<int> parent(V, -1);
    int totalWeight = 0;

    for (const auto &edge : edges) {
      int u = edge.u;
      int v = edge.v;
      int weight = edge.weight;

      int x = find(parent, u);
      int y = find(parent, v);

      if (x != y) {
        result.push_back({u, v});
        totalWeight += weight;
        Union(parent, x, y);
      }
    }
    return totalWeight;
  }

private:
  int find(vector<int> &parent, int i) {
    if (parent[i] == -1)
      return i;
    return parent[i] = find(parent, parent[i]); // Path compression
  }

  void Union(vector<int> &parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset) {
      parent[xset] = yset;
    }
  }
};

void printQ(const queue<int> &q) {
  queue<int> copyQueue = q;

  while (!copyQueue.empty()) {
    int frontElement = copyQueue.front();
    std::cout << frontElement << " ";
    copyQueue.pop();
  }
  cout << endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
}

int main() {

  int size, edges;
  while (cin >> size >> edges) {
    // Graph g(size);
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
      // printQ(q);
      found.insert(locations[u]);

      for (const auto &neighbor : v[u])
        if (!visited[neighbor] && found.count(neighbor))
          visited[neighbor] = true, q.push(neighbor);
      // printQ(q);
    }
    bool flag = true;
    for (const auto &pos : visited)
      if (!pos)
        flag = false;
    cout << (flag ? "sim" : "nao") << endl;
  }
  return 0;
}
