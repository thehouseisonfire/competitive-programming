#include <iostream>
#include <unordered_map>

#define uint unsigned int

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  uint n, m;
  cin >> n >> m;
  unordered_map<uint, uint> map;
  while (m--) {
    uint a, b;
    cin >> a >> b;
    map[a]++;
    map[b]++;
  }

  string message = "Rambo esta salvo";

  for (const auto &pos : map)
    if (pos.second % 2) {
      message = "Rambo esta perdido";
      break;
    }

  cout << message << endl;

  return 0;
}
