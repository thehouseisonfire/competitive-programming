
#include <iostream>

using namespace std;

bool selectionSort(string &arr, int n) {
  int i, j, min_idx;
  bool flag = 0;
  // One by one move boundary of
  // unsorted subarray
  for (i = 0; i < n - 1; i++) {

    // Find the minimum element in
    // unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }

    // Swap the found minimum element
    // with the first element
    if (min_idx != i) {
      swap(arr[min_idx], arr[i]);
      if (flag)
        return true;
      else
        flag = true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  string str;
  str.reserve(26);
  int t, num_letters;
  cin >> t;
  while (t--) {
    cin >> num_letters;
    cin >> str;
    selectionSort(str, num_letters) ? cout << "There aren't the chance." << endl
                                    : cout << "There are the chance." << endl;
    str.clear();
  }
  return 0;
}
