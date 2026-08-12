#include <iostream>
#include <queue>
#include <vector>

#define NOT_VISITED '.'
#define VISITED '!'
#define SEP 'o'

using namespace std;

void mark_pool(vector<vector<char>> &mtx, const pair<int, int> s,
               const pair<int, int> d) {
  mtx[s.first][s.second] = VISITED;
  queue<pair<int, int>> q;
  q.push(make_pair(s.first, s.second));

  int count = 0;
  while (!q.empty()) {
    count++;
    const pair<int, int> p = q.front();
    mtx[p.first][p.second] = VISITED;
    if (p.first > 0 && mtx[p.first - 1][p.second] == NOT_VISITED) {
      mtx[p.first - 1][p.second] = VISITED;
      q.push(make_pair(p.first - 1, p.second));
    }
    if (p.first < d.first - 1 && mtx[p.first + 1][p.second] == NOT_VISITED) {
      mtx[p.first + 1][p.second] = VISITED;
      q.push(make_pair(p.first + 1, p.second));
    }
    if (p.second > 0 && mtx[p.first][p.second - 1] == NOT_VISITED) {
      mtx[p.first][p.second - 1] = VISITED;
      q.push(make_pair(p.first, p.second - 1));
    }
    if (p.second < d.second - 1 && mtx[p.first][p.second + 1] == NOT_VISITED) {
      mtx[p.first][p.second + 1] = VISITED;
      q.push(make_pair(p.first, p.second + 1));
    }
    // return;
    q.pop();
  }
}
int solution(vector<vector<char>> &mtx, int h, int w) {
  int count = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (mtx[i][j] == NOT_VISITED) {
        mark_pool(mtx, make_pair(i, j), make_pair(h, w));
        count++;
      }
    }
  return count;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  vector<vector<char>> mtx(h, vector<char>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> mtx[i][j];
  cout << solution(mtx, h, w) << endl;
  return 0;
}
