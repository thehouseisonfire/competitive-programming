#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printGrid(const vector<string> &grid, int C) {
  for (const string &row : grid) {
    cout << row << endl;
  }
  for (int i = 0; i < C; ++i) {
    cout << '+';
  }
  cout << endl;
}

void overlayGrids(const vector<string> &grid1, const vector<string> &grid2,
                  int R, int C) {
  vector<string> result(R, string(C, ' '));
  int maxShared = 0;
  vector<string> bestResult;

  for (int dx = -C + 1; dx < C; ++dx) {
    for (int dy = -R + 1; dy < R; ++dy) {
      vector<string> currentResult(R, string(C, ' '));
      int shared = 0;

      for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
          if (i + dy >= 0 && i + dy < R && j + dx >= 0 && j + dx < C) {
            if (grid1[i][j] == grid2[i + dy][j + dx]) {
              currentResult[i][j] = grid1[i][j];
              shared++;
            } else {
              currentResult[i][j] = grid1[i][j];
            }
          } else {
            currentResult[i][j] = grid1[i][j];
          }
        }
      }

      if (shared > maxShared) {
        maxShared = shared;
        bestResult = currentResult;
      }
    }
  }

  printGrid(bestResult, C);
}

int main() {
  int R, C;
  while (cin >> R >> C) {
    if (R == 0 || C == 0)
      break;

    vector<string> grid1(R);
    vector<string> grid2(R);

    for (int i = 0; i < R; ++i) {
      cin >> grid1[i];
    }

    for (int i = 0; i < R; ++i) {
      cin >> grid2[i];
    }

    overlayGrids(grid1, grid2, R, C);
  }

  return 0;
}
