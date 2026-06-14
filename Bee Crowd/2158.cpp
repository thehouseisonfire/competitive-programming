#include <iostream>

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

// relação de Euler para poliedros convexos:

// 𝑉 − 𝐸 + 𝐹 = 2

// Onde:
//
// E = F/2, pois cada aresta eh dividida por dois atomos (obviamente)
// V = F/3, pois cada vertices esta presente em 3 faces
// *(ou, em outra maneira de dizer, cada vertice tem 3 arestas)* <-- TEORIA

// E, neste caso

// F = 5*FP + 6*FH (Faces Pentagonais tem 5 moleculas e Hexagonais, 6) {neste
// caso! ajuste em relacao as faces!}

pll solve(ll fp, ll fh) {
  llu F = fp + fh;

  llu E = (5 * fp + 6 * fh) / 2;

  llu V = E - F + 2; // so assim funciona neste problema (??), mas
  // vale por lembrar que podemos descobrir os outros com esste equacao

  return {V, E};
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll fp, fh;
  ll count = 1;
  while (cin >> fp >> fh) {
    cout << "Molecula #" << count << ".:." << endl;
    const auto [v, e] = solve(fp, fh);
    cout << "Possui " << v << " atomos e " << e << " ligacoes" << endl << endl;
    count++;
  }

  return 0;
}
