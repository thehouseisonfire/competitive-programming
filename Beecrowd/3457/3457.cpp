#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int solution();
int solution(const int num, const vector<int> &choices, vector<int> &results);

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  unordered_set<int> s;
  for (int i = 0; i < n; i++) {
    int aux;
    cin >> aux;
    s.insert(aux);
  }
  INPUT_VEC(v);
  set<int> answers;
  int mg = *s.begin();
  for (const auto &e : v) {
    int res = e + mg;
    bool flag = true;
    for (const auto &e2 : v) {
      if (s.find(res + e2) == s.end() && s.find(res - e2) == s.end()) {
        flag = false;
        break;
      }
    }
    if (flag)
      answers.insert(res);

    res = e - mg;
    flag = true;
    for (const auto &e2 : v) {
      if (s.find(res + e2) == s.end() && s.find(res - e2) == s.end()) {
        flag = false;
        break;
      }
    }
    if (flag)
      answers.insert(res);
  }
  // sort(v.begin(), v.end());
  // auto halfpoint = u.begin() + u.size() / 2;
  // sort(u.begin(), halfpoint, greater<int>());
  // sort(halfpoint + 1, u.end());
  // PRINT_VEC(v);
  PRINT_VEC(s);

  return 0;
}
