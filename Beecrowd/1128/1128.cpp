#include <cstdio>
#include <vector>
#define MAX 2020
using namespace std;
int visitado[MAX], n, m;
vector<int> grafo[MAX], transposto[MAX];

int dfs1(int u) {
  visitado[u] = 1;
  int retornar = 1;
  for (int v : grafo[u]) {
    if (!visitado[v]) {
      retornar += dfs1(v);
    }
  }
  return retornar;
}

int dfs2(int u) {
  visitado[u] = 0;
  int retornar = 1;
  for (int v : transposto[u]) {
    if (visitado[v]) {
      retornar += dfs2(v);
    }
  }
  return retornar;
}

int main() {
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0)
      break;
    for (int i = 1; i <= n; i++) {
      grafo[i].clear();
      transposto[i].clear();
      visitado[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int origem, destino, mao;
      scanf("%d %d %d", &origem, &destino, &mao);
      if (mao == 2) {
        grafo[origem].push_back(destino);
        transposto[destino].push_back(origem);
        grafo[destino].push_back(origem);
        transposto[origem].push_back(destino);
      } else {
        grafo[origem].push_back(destino);
        transposto[destino].push_back(origem);
      }
    }
    if (dfs1(1) != n) {
      printf("0\n");
      continue;
    }
    if (dfs2(1) != n) {
      printf("0\n");
      continue;
    }
    printf("1\n");
  }
  return 0;
}
