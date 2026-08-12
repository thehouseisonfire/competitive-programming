#include <iostream>

using namespace std;
const int N = 1123;
int t[N + N][N + N];
int n;

void build() {
  for (int i = n; i < n + n; i++)
    for (int j = n - 1; j > 0; j--)
      t[i][j] = t[i][j << 1] + t[i][j << 1 | 1];
  for (int i = 1; i < n + n; i++) {
    for (int j = n - 1; j > 0; j--)
      t[j][i] = t[j << 1][i] + t[j << 1 | 1][i];
  }
}

long query(int l, int u, int r, int d) {
  long asw = 0;
  for (l += n, r += n; l <= r; ++l >>= 1, --r >>= 1) {
    for (int i = u + n, j = d + n; i <= j; ++i >>= 1, --j >>= 1) {
      if (l & 1) {
        if (i & 1)
          asw += t[l][i];
        if (!(j & 1))
          asw += t[l][j];
      }
      if (!(r & 1)) {
        if (i & 1)
          asw += t[r][i];
        if (!(j & 1))
          asw += t[r][j];
      }
    }
  }
  return asw;
}

int main(int argc, char *argv[]) {

  char aux;
  int m, x1, x2, y1, y2;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> aux;
      t[i + n][j + n] = aux == '*' ? 1 : 0;
    }
  }

  build();

  while (m--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
  }
}
