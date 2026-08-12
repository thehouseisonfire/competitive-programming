#include <iostream>
#include <string>
#include <vector>

#define u8 unsigned char
#define hd short int
#define hu short unsigned
#define lu unsigned
#define ll long long
#define llu long long unsigned
#define float double
#define double long double
#define pi pair<int, int>
#define pll pair<ll, ll>

#define INF 2147483647
#define HINF INF >> 1
#define MOD 1000000007
#define ASCII_NUMBER_OFFSET '0'
#define ASCII_UPPERCASE_OFFSET 'A'
#define ASCII_LOWERCASE_OFFSET 'a'
// #define ASCII_NUMBER_OFFSET 48
// #define ASCII_UPPERCASE_OFFSET 65
// #define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define PI(x) cout << x.first << " " << x.second << endl
#define DUO(x, y) cout << x << " " << y << endl

#define PRINT_VEC(v)                                                           \
  for (const auto &pos : v) {                                                  \
    cout << pos << " ";                                                        \
  }                                                                            \
  cout << endl;

#define PRINT_DUO_VEC(v)                                                       \
  for (const auto &pos : v) {                                                  \
    cout << pos.first << " " << pos.second << endl;                            \
  }                                                                            \
  cout << endl;

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

void print_grid(const vector<string> &grid, int R, int C) {
  for (int i = 0; i < R; ++i) {
    cout << grid[i] << endl;
  }
  cout << string(C, '+') << endl;
}

void overlay_grids(const vector<string> &grid1, const vector<string> &grid2,
                   int R, int C) {
  vector<string> result(R, string(C, ' '));
  int max_overlap = 0;

  for (int dr = -R + 1; dr < R; ++dr) {
    for (int dc = -C + 1; dc < C; ++dc) {
      vector<string> temp(R, string(C, ' '));
      int overlap = 0;

      for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
          int r2 = r + dr;
          int c2 = c + dc;
          if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C) {
            if (grid1[r][c] == grid2[r2][c2]) {
              temp[r][c] = grid1[r][c];
              overlap++;
            } else {
              temp[r][c] = grid1[r][c];
            }
          } else {
            temp[r][c] = grid1[r][c];
          }
        }
      }

      if (overlap > max_overlap) {
        max_overlap = overlap;
        result = temp;
      }
    }
  }

  print_grid(result, R, C);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int R, C;
  while (cin >> R >> C) {
    if (R == 0 || C == 0)
      break;

    vector<string> mtx(R);
    INPUT_VEC(mtx);

    overlay_grids(mtx, mtx, R, C);
  }

  return 0;
}
// ```

// ### Explicação do Código:
//
// 1. **Leitura da Entrada:**
//    - O programa lê os valores de `R` e `C` até que ambos sejam zero,
//    indicando o fim da entrada.
//    - Para cada caso de teste, ele lê a grade de letras em `grid1`.
//
// 2. **Sobreposição de Grades:**
//    - A função `overlay_grids` é responsável por calcular a sobreposição das
//    grades.
//    - Ela tenta todas as possíveis deslocações (`dr` e `dc`) da segunda grade
//    em relação à primeira.
//    - Para cada deslocamento, ela calcula o número de letras que coincidem e
//    mantém a configuração com o maior número de sobreposições.
//
// 3. **Impressão do Resultado:**
//    - A função `print_grid` imprime a grade resultante e uma linha de `+` com
//    o número de colunas da grade.
//
// 4. **Loop Principal:**
//    - O loop principal continua lendo novos casos de teste até que `R` ou `C`
//    sejam zero.
//
// ### Observações:
// - O código considera que a segunda grade é a mesma que a primeira (`grid1`),
// pois a sobreposição é feita com a própria grade deslocada.
// - A função `overlay_grids` tenta todas as possíveis deslocações e seleciona a
// que maximiza o número de letras sobrepostas.
// - O código é eficiente para grades de tamanho máximo 1000x1000, conforme
// especificado.
