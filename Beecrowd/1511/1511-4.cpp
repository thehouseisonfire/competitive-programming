#include <iostream>

using namespace std;

const int N = 1123;
int t[N + N][N + N];
int n;

int op(int a, int b) { return a + b; };

// Build the 2D segment tree
void build() {
  // Build for columns
  for (int i = n; i < n + n; i++)
    for (int j = n - 1; j > 0; j--)
      t[i][j] = op(t[i][j << 1], t[i][j << 1 | 1]);

  // Build for rows
  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < n + n; j++)
      t[i][j] = op(t[i << 1][j], t[i << 1 | 1][j]);
}

// Update the value at (x, y) and propagate the changes in both row and column
// trees
void update(int x, int y, int val) {
  t[x + n][y + n] = val; // Update the original value at the leaf

  // Update column segment tree for this row
  for (int j = y + n; j > 1; j >>= 1)
    t[x + n][j >> 1] = op(t[x + n][j], t[x + n][j ^ 1]);

  // Update row segment tree
  for (int i = x + n; i > 1; i >>= 1)
    for (int j = y + n; j > 0; j >>= 1)
      t[i >> 1][j] = op(t[i][j], t[i ^ 1][j]);
}

// Query the sum (or op) over the submatrix (l, u) to (r, d) inclusive
long query(int l, int u, int r, int d) {
  long res = 0;
  for (l += n, r += n; l <= r; ++l >>= 1, --r >>= 1) {
    for (int i = u + n, j = d + n; i <= j; ++i >>= 1, --j >>= 1) {
      if (l & 1) {
        if (i & 1)
          res = op(res, t[l][i++]);
        if (!(j & 1))
          res = op(res, t[l][j--]);
      }
      if (!(r & 1)) {
        if (i & 1)
          res = op(res, t[r][i++]);
        if (!(j & 1))
          res = op(res, t[r][j--]);
      }
    }
  }
  return res;
}

int main() {
  char aux;
  int m, x1, x2, y1, y2;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> aux;
      t[i + n][j + n] = aux == '*' ? 1 : 0;
    }
  }

  build(); // Build the 2D segment tree

  while (m--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
  }

  // Example update: set the value at (2, 3) to 5
  update(2, 3, 5);

  // Query again after the update
  cout << query(0, 0, 3, 3) << endl;

  return 0;
}
