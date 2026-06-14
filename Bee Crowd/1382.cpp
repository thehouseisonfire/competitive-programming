#include <algorithm>
#include <iostream>
#include <map>

#define u8 unsigned char
#define hd short int
#define hu short unsigned
#define lu unsigned
#define ll long long
#define llu long long unsigned
#define float double
#define double long double
#define pi pair<int, int>
#define pll pair<ll, ll>

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

const int len = 10000;

int nums[len];
bool visited[len] = {0};

int minSwaps(int nums[], int n) {
  int len = n;
  map<int, int> map;
  for (int i = 0; i < len; i++)
    map[nums[i]] = i, visited[i] = 0;

  sort(nums, nums + n);

  int ans = 0;
  for (int i = 0; i < len; i++) {

    if (visited[i] || map[nums[i]] == i)
      continue;

    int j = i, cycle_size = 0;
    while (!visited[j]) {
      visited[j] = true;

      j = map[nums[j]];
      cycle_size++;
    }

    if (cycle_size > 0) {
      ans += (cycle_size - 1);
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    // cout << m << endl;
    for (int i = 0; i < m; i++)
      cin >> nums[i];
    cout << minSwaps(nums, m) << endl;
  }

  return 0;
}
