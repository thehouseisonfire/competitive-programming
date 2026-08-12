#include <iostream>
#include <unordered_map>
#include <vector>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

using namespace std;

int solution();

int main(int argc, char *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  while (true) {
    int n, m;
    unordered_map<int, bool> map;
    cin >> n;
    if (!n)
      return 0;
    while (n--) {
      cin >> m;
      // map[m] ? map[m] = false : map[m] = true;
      map[m] ^= true;
    }
    int f, s;
    bool first = true;
    for (auto a : map) {
      if (a.second) {
        if (first) {
          f = a.first;
          first = false;
        } else {
          s = a.first;
        }
      }
    }
    if (f > s) {
      int aux = f;
      f = s;
      s = aux;
    }
    cout << f << " " << s << endl;
  }
  return 0;
}
