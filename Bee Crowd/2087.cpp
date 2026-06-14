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

const int K = 26;

struct Vertex {
  int next[K];
  bool output = false;

  Vertex() { fill(begin(next), end(next), -1); }
};

vector<Vertex> trie(1);

void add_string(string const &s) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[c];
  }
  trie[v].output = true;
}

bool searchKey(const string &key) {

  int v = 0;

  for (char ch : key) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1)
      return false;
    v = trie[v].next[c - 'a'];
  }
  return trie[v].output;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  bool flag = true;
  while (cin >> n && n) {
    while (n--) {
      string s;
      cin >> s;
      cout << searchKey(s) << endl;
      if (searchKey(s))
        flag = false;
      // break;
      add_string(s);
    }
    cout << (flag ? "Conjunto Bom" : "Conjunto Ruim") << endl;
  }

  return 0;
}
