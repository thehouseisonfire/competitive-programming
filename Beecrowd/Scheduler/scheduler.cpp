#include <algorithm>
#include <iostream>
#include <vector>

#define u8 unsigned char
#define i16 short int
#define u16 short unsigned
#define u32 unsigned
#define pi pair<int, int>

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

#define INPUT_VEC(v)                                                           \
  for (auto &pos : v) {                                                        \
    cin >> pos;                                                                \
  }

#define INPUT_DUO_VEC(v)                                                       \
  for (auto &pos : v) {                                                        \
    cin >> pos.first >> pos.second;                                            \
  }

using namespace std;

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tasks, time;
  while (cin >> tasks >> time) {
    vector<pi> v(tasks);
    for (auto &pos : v)
      cin >> pos.first >> pos.second;
    sort(v.rbegin(), v.rend());

    int revenue = 0, max = 0;
    for (const auto &pos : v)
      max += pos.first;

    vector<int> time_ladder(time + 1, 0);

    for (const auto &pos : v) {
      if (time_ladder[pos.second] >= pos.second)
        continue;

      revenue += pos.first;
      for (int i = pos.second; i <= time; i++)
        time_ladder[i]++;

      for (int i = pos.second - 1; i >= 0; i--)
        time_ladder[i] = std::max(time_ladder[i], time_ladder[i + 1] - 1);
      // if (time_ladder[i] < time_ladder[i + 1] - 1)
      //   time_ladder[i] = time_ladder[i + 1] - 1;
    }
    cout << max - revenue << endl;
  }
  return 0;
}
