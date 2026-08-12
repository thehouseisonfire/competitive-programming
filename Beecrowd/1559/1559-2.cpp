#include <iostream>
#include <vector>

using namespace std;

bool canMoveLeft(const vector<vector<int>> &board) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j < 4; ++j) { // Start from the second column
      if (board[i][j] != 0) {
        if (board[i][j - 1] == 0 || board[i][j - 1] == board[i][j]) {
          return true;
        }
      }
    }
  }
  return false;
}

bool canMoveRight(const vector<vector<int>> &board) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 2; j >= 0; --j) { // Start from the third column
      if (board[i][j] != 0) {
        if (board[i][j + 1] == 0 || board[i][j + 1] == board[i][j]) {
          return true;
        }
      }
    }
  }
  return false;
}

bool canMoveUp(const vector<vector<int>> &board) {
  for (int j = 0; j < 4; ++j) {
    for (int i = 1; i < 4; ++i) { // Start from the second row
      if (board[i][j] != 0) {
        if (board[i - 1][j] == 0 || board[i - 1][j] == board[i][j]) {
          return true;
        }
      }
    }
  }
  return false;
}

bool canMoveDown(const vector<vector<int>> &board) {
  for (int j = 0; j < 4; ++j) {
    for (int i = 2; i >= 0; --i) { // Start from the third row
      if (board[i][j] != 0) {
        if (board[i + 1][j] == 0 || board[i + 1][j] == board[i][j]) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int numTests;
  cin >> numTests;

  while (numTests--) {
    vector<vector<int>> board(4, vector<int>(4));

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> board[i][j];
      }
    }

    bool left = canMoveLeft(board);
    bool right = canMoveRight(board);
    bool up = canMoveUp(board);
    bool down = canMoveDown(board);

    if (left || right || up || down) {
      if (down)
        cout << "DOWN ";
      if (left)
        cout << "LEFT ";
      if (right)
        cout << "RIGHT ";
      if (up)
        cout << "UP ";
      cout << endl;
    } else {
      cout << "NONE" << endl;
    }
  }

  return 0;
}
