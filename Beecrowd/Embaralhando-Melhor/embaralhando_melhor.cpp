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

// 1 2
// 2 1
// 1 2
//
// 1 2 3 4 - 2 1 3 4 -
// 3 1 4 2
// 4 3 2 1
// 2 4 1 3
// 1 2 3 4
//
// 1 2 3 4 5 6
// 4 1 5 2 6 3
// 2 4 6 1 3 5
// 1 2 3 4 5 6
//
// 1 2 3 4 5 6 7 8
// 5 1 6 2 7 3 8 4
// 7 5 3 1 8 6 4 2
// 8 7 6 5 4 3 2 1
// 4 8 3 7 2 6 1 5
// 2 4 6 8 1 3 5 7
// 1 2 3 4 5 6 7 8

// MELHOR ALGORITMO:
//
// 1. pegue um index qualquer (para simplicidade, vamos usar o index[0])
// 2. ele vai dobrar o seu index to da interacao (0 -> 1 - > 3 -> 7...)
// (primeiro -> segundo -> quarto...)
// 3. se ele sobrepassar o limite do array, deve ir para ( (nova 'posicao') %
// array.length() ) -1 3.1. ele deve dobra na nova posicao 3.2. exemplo para 8
// (0->1->3->7->6->4->0) 3.2. exemplo para 8 (1->2->4->8->7->4->0)

bool sorted(const vector<int> &v) {
  for (int i = 1; i < v.size(); i++)
    if (v[i - 1] > v[i])
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int len, count = 1;
  vector<int> v;
  cin >> len;
  v.reserve(len);
  const int half = len >> 1;
  for (int i = 1; i <= half; i++) {
    v.push_back(half + i);
    v.push_back(i);
  }
  while (!sorted(v)) {
    const vector<int> w(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i < len; i += 2) {
      v[i] = w[half + j];
      v[i + 1] = w[j];
      j++;
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
