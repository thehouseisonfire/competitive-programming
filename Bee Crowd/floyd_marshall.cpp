#include <vector>

#define INF 99999

// ATENÇÃO: MARCAR NEGATIVOS COM INF A MENOS QUE SEJAM DA DIAGONAL PRINCIPAL
void floydWarshall(std::vector<std::vector<int>> &v) {

  size_t i, j, k;
  const size_t size = v.size();
  for (k = 0; k < size; k++)
    for (i = 0; i < size; i++)
      for (j = 0; j < size; j++)
        if (v[i][j] > (v[i][k] + v[k][j]) && (v[k][j] != INF && v[i][k] != INF))
          v[i][j] = v[i][k] + v[k][j];
}
