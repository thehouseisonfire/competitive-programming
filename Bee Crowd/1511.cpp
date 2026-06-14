#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int MAXN = 1001; // Limite máximo do tabuleiro
const int INF = 1e9;   // Um valor grande para inicializações

struct SegmentTree2D {
  int n, m;
  vector<vector<int>> tree;

  SegmentTree2D(int n, int m) : n(n), m(m) {
    tree.assign(4 * n, vector<int>(4 * m, 0));
  }

  void update_y(int node_x, int start_x, int end_x, int node_y, int start_y,
                int end_y, int x, int y, int val) {
    if (start_y == end_y) {
      if (start_x == end_x) {
        tree[node_x][node_y] = val;
      } else {
        tree[node_x][node_y] =
            gcd(tree[2 * node_x][node_y], tree[2 * node_x + 1][node_y]);
      }
    } else {
      int mid_y = (start_y + end_y) / 2;
      if (y <= mid_y)
        update_y(node_x, start_x, end_x, 2 * node_y, start_y, mid_y, x, y, val);
      else
        update_y(node_x, start_x, end_x, 2 * node_y + 1, mid_y + 1, end_y, x, y,
                 val);
      tree[node_x][node_y] =
          gcd(tree[node_x][2 * node_y], tree[node_x][2 * node_y + 1]);
    }
  }

  void update_x(int node_x, int start_x, int end_x, int x, int y, int val) {
    if (start_x == end_x) {
      update_y(node_x, start_x, end_x, 1, 0, m - 1, x, y, val);
    } else {
      int mid_x = (start_x + end_x) / 2;
      if (x <= mid_x)
        update_x(2 * node_x, start_x, mid_x, x, y, val);
      else
        update_x(2 * node_x + 1, mid_x + 1, end_x, x, y, val);
      update_y(node_x, start_x, end_x, 1, 0, m - 1, x, y, val);
    }
  }

  int query_y(int node_x, int node_y, int start_y, int end_y, int y1, int y2) {
    if (y1 > y2)
      return 0;
    if (start_y == y1 && end_y == y2) {
      return tree[node_x][node_y];
    }
    int mid_y = (start_y + end_y) / 2;
    return gcd(query_y(node_x, 2 * node_y, start_y, mid_y, y1, min(y2, mid_y)),
               query_y(node_x, 2 * node_y + 1, mid_y + 1, end_y,
                       max(y1, mid_y + 1), y2));
  }

  int query_x(int node_x, int start_x, int end_x, int x1, int x2, int y1,
              int y2) {
    if (x1 > x2)
      return 0;
    if (start_x == x1 && end_x == x2) {
      return query_y(node_x, 1, 0, m - 1, y1, y2);
    }
    int mid_x = (start_x + end_x) / 2;
    return gcd(query_x(2 * node_x, start_x, mid_x, x1, min(x2, mid_x), y1, y2),
               query_x(2 * node_x + 1, mid_x + 1, end_x, max(x1, mid_x + 1), x2,
                       y1, y2));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int Q;
  while (cin >> Q) {
    SegmentTree2D segtree(MAXN, MAXN); // Inicializando a Segment Tree 2D
    for (int i = 0; i < Q; i++) {
      string type;
      int x, y, d;
      cin >> type >> x >> y >> d;
      if (type == "SET") {
        segtree.update_x(1, 0, MAXN - 1, x + 500, y + 500, d);
      } else if (type == "QUERY") {
        int gcd_val = 0;
        for (int dx = -d; dx <= d; ++dx) {
          int dist_y = d - abs(dx);
          gcd_val = gcd(gcd_val, segtree.query_x(1, 0, MAXN - 1, x + dx + 500,
                                                 x + dx + 500, y - dist_y + 500,
                                                 y + dist_y + 500));
        }
        cout << gcd_val << "\n";
      }
    }
  }

  return 0;
}
