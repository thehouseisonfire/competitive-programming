#include <bits/stdc++.h>

using namespace std;

void swap(int *start, const int i, const int j) {
  const int aux = start[i];
  start[i] = start[j];
  start[j] = aux;
}

const int solution(int *start, const int *finish, const int n) {
  int overtakes = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (start[j] == finish[i]) {
        int aux = start[j];
        for (int k = j; k > i; k--) {
          start[k] = start[k - 1];
          overtakes++;
        }
        start[i] = aux;
      }
  return overtakes;
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    int start[n];
    int finish[n];
    for (int i = 0; i < n; i++) {
      cin >> start[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> finish[i];
    }
    cout << solution(start, finish, n) << endl;
  }
  return 0;
}
