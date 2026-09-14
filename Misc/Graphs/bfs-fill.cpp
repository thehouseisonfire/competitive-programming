#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

template <typename Condition, typename Action>
void bfs_fill(int sx, int sy, int n, int m, Condition can_visit,
              Action on_visit) {
  queue<pii> q;
  q.push({sx, sy});
  on_visit(sx, sy);

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m || !can_visit(nx, ny))
        continue;

      on_visit(nx, ny);
      q.push({nx, ny});
    }
  }
}
