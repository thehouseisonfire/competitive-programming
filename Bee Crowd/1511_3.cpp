#include <iostream>
#include <numeric>
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

#define INPUT_VEC(v, n)                                                        \
  for (size_t i = n; i < n + n; i++)                                           \
    cin >> v[i];

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

const int MAX = 2 * 1e3;
int n, m; // n = number of rows, m = number of columns
vector<vector<int>> v(2 * MAX, vector<int>(2 * MAX));

int op(int a, int b) { return (a + b); }

// Build the inner (column) segment tree for a specific row `row`
void build_y(int row, int node_x, int node_y, int l_y, int r_y) {
  if (l_y + 1 == r_y) {
    v[node_x][node_y] =
        v[node_x + n][l_y + m]; // Initialize leaf nodes with the grid values
  } else {
    int mid_y = (l_y + r_y) / 2;
    build_y(row, node_x, 2 * node_y, l_y, mid_y);
    build_y(row, node_x, 2 * node_y + 1, mid_y, r_y);
    v[node_x][node_y] = op(v[node_x][2 * node_y], v[node_x][2 * node_y + 1]);
  }
}

// Build the outer (row) segment tree
void build_x(int node_x, int l_x, int r_x) {
  if (l_x + 1 == r_x) {
    build_y(l_x, node_x + n, 1, 0, m); // Build the column tree for each row
  } else {
    int mid_x = (l_x + r_x) / 2;
    build_x(2 * node_x, l_x, mid_x);
    build_x(2 * node_x + 1, mid_x, r_x);

    // Combine results from child nodes
    for (int j = 1; j < 2 * m; ++j) {
      v[node_x][j] = op(v[2 * node_x][j], v[2 * node_x + 1][j]);
    }
  }
}

// Update column tree for a specific row
void update_y(int node_x, int node_y, int l_y, int r_y, int col, int val) {
  if (l_y + 1 == r_y) {
    v[node_x][node_y] = val; // Update the leaf node in the column tree
  } else {
    int mid_y = (l_y + r_y) / 2;
    if (col < mid_y)
      update_y(node_x, 2 * node_y, l_y, mid_y, col, val);
    else
      update_y(node_x, 2 * node_y + 1, mid_y, r_y, col, val);
    v[node_x][node_y] = op(v[node_x][2 * node_y], v[node_x][2 * node_y + 1]);
  }
}

// Update outer tree (and propagate to inner tree)
void update_x(int node_x, int l_x, int r_x, int row, int col, int val) {
  if (l_x + 1 == r_x) {
    update_y(node_x + n, 1, 0, m, col, val); // Update column segment tree
  } else {
    int mid_x = (l_x + r_x) / 2;
    if (row < mid_x)
      update_x(2 * node_x, l_x, mid_x, row, col, val);
    else
      update_x(2 * node_x + 1, mid_x, r_x, row, col, val);

    // After updating, propagate the change upwards
    for (int j = 1; j < 2 * m; ++j) {
      v[node_x][j] = op(v[2 * node_x][j], v[2 * node_x + 1][j]);
    }
  }
}

// Query the inner (column) segment tree
int query_y(int node_x, int node_y, int l_y, int r_y, int ql_y, int qr_y) {
  if (ql_y >= r_y || qr_y <= l_y)
    return 0; // Out of bounds, return GCD identity (0)
  if (ql_y <= l_y && r_y <= qr_y)
    return v[node_x][node_y]; // Fully in range
  int mid_y = (l_y + r_y) / 2;
  return op(query_y(node_x, 2 * node_y, l_y, mid_y, ql_y, qr_y),
            query_y(node_x, 2 * node_y + 1, mid_y, r_y, ql_y, qr_y));
}

// Query the outer (row) segment tree
int query_x(int node_x, int l_x, int r_x, int ql_x, int qr_x, int ql_y,
            int qr_y) {
  if (ql_x >= r_x || qr_x <= l_x)
    return 0; // Out of bounds, return GCD identity (0)
  if (ql_x <= l_x && r_x <= qr_x)
    return query_y(node_x, 1, 0, m, ql_y, qr_y); // Fully in range
  int mid_x = (l_x + r_x) / 2;
  return op(query_x(2 * node_x, l_x, mid_x, ql_x, qr_x, ql_y, qr_y),
            query_x(2 * node_x + 1, mid_x, r_x, ql_x, qr_x, ql_y, qr_y));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  n = 4;
  m = 4;

  // Example 2D grid (you can modify this)
  vector<vector<int>> grid = {
      {2, 4, 6, 8}, {3, 6, 9, 12}, {5, 10, 15, 20}, {7, 14, 21, 28}};

  // Initialize the 2D segment tree with the grid values
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      v[i + n][j + m] = grid[i][j];

  // Build the 2D segment tree
  build_x(1, 0, n);

  // Example query for GCD in submatrix from (1,1) to (3,3)
  cout << query_x(1, 0, n, 1, 3, 1, 3) << endl;

  // Example update: Set grid[2][2] = 18
  update_x(1, 0, n, 2, 2, 18);

  // Query again after update
  cout << query_x(1, 0, n, 1, 3, 1, 3) << endl;

  return 0;
}

// int main(int argc, char *argv[]) {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
//   int q;
//   cin >> n >> q;
//   INPUT_VEC(v, n)
//   build();
//   while (q--) {
//     int k, a, b;
//     cin >> k >> a >> b;
//     a--;
//     if (k == 1)
//       modify(a, b);
//     if (k == 2)
//       cout << query(a, b) << endl;
//   }
//
//   return 0;
// }
