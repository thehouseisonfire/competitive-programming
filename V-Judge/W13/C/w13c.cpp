#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int theta, N;
  cin >> theta >> N;

  double theta_rad = theta * M_PI / 180.0;
  double tan_theta = tan(theta_rad);

  vector<pi> shadows(N);
  for (int i = 0; i < N; i++) {
    double X, H;
    cin >> X >> H;

    double shadow_end = X + H / tan_theta;
    shadows[i] = {X, shadow_end};
  }

  sort(shadows.begin(), shadows.end());

  double total_length = 0.0;
  double current_start = shadows[0].first;
  double current_end = shadows[0].second;

  for (int i = 1; i < N; i++) {
    double start = shadows[i].first;
    double end = shadows[i].second;

    if (start <= current_end) {
      current_end = max(current_end, end);
    } else {
      total_length += current_end - current_start;
      current_start = start;
      current_end = end;
    }
  }

  total_length += current_end - current_start;

  cout << fixed << std::setprecision(12) << total_length << endl;

  return 0;

  return 0;
}
