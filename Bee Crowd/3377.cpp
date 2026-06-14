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

struct Area {
  double area;
  int x, y;
};

int quantidade(const string &s, char c) { return count(s.begin(), s.end(), c); }

double inclinacao(const string &s) {
  return (double)(quantidade(s, 'U')) / quantidade(s, 'R');
}

double area(double alfa, int x, int y) {
  if (alfa * (x - 1) >= y || alfa * x <= y) {
    return abs(alfa * (x - 0.5) - y);
  } else {
    double xr = (y / alfa - x) / 2.0;
    return xr * (y - alfa * x) + (xr + 0.5) * (y - alfa * (x - 1));
  }
}

Area calc_area(const Area &a, char c, double alfa) {
  if (c == 'R') {
    return {a.area + area(alfa, a.x + 1, a.y), a.x + 1, a.y};
  } else {
    return {a.area, a.x, a.y + 1};
  }
}

int main() {
  string entrada;
  int t = 1;
  Area inicio = {0.0, 0, 0};

  while (cin >> entrada && entrada != "S") {
    double alfa = inclinacao(entrada);
    Area area_total = inicio;

    for (char c : entrada) {
      if (c == 'S')
        break;
      area_total = calc_area(area_total, c, alfa);
    }

    cout << fixed << setprecision(3) << t << ". " << area_total.area << endl;
    t++;
  }

  return 0;
}
