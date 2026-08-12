#include <iostream>
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

// #include <iomanip> <-- NEEDED IMPORT
#define precision_print(x, r)                                                  \
  std::cout << std::fixed << std::showpoint;                                   \
  std::cout << std::setprecision(r);                                           \
  std::cout << x << std::endl;
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

void floydWarshall(std::vector<std::vector<int>> &v) {

  size_t i, j, k;
  const size_t size = v.size();
  for (k = 0; k < size; k++)
    for (i = 0; i < size; i++)
      for (j = 0; j < size; j++)
        if (v[i][j] > (v[i][k] + v[k][j]) && (v[k][j] != INF && v[i][k] != INF))
          v[i][j] = v[i][k] + v[k][j];
}

void fixMatrix(vector<vector<int>> &v) {
  size_t i, j;
  const size_t size = v.size();
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      if (!v[i][j] && i != j)
        v[i][j] = INF;
}

void printSolution(const vector<vector<int>> &v) {
  cout << "The following matrix shows the shortest "
          "distances"
          " between every pair of vertices \n";
  const int size = v.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (v[i][j] == INF)
        cout << "INF"
             << " ";
      else
        cout << v[i][j] << "   ";
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(n, 0));
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    v[a][b] = c;
  }
  printSolution(v);
  fixMatrix(v);
  printSolution(v);
  floydWarshall(v);
  printSolution(v);
  int k;
  cin >> k;
  while (k--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    const int res = v[a][b];
    cout << (res > c ? res : -1) << endl;
  }

  return 0;
}
