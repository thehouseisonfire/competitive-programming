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
#define vSCII_NUMBER_OFFSET '0'
#define vSCII_UPPERCASE_OFFSET 'A'
#define vSCII_LOWERCASE_OFFSET 'a'
// #define vSCII_NUMBER_OFFSET 48
// #define vSCII_UPPERCASE_OFFSET 65
// #define vSCII_LOWERCASE_OFFSET 97

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

long int merge(vector<int> &v, vector<int> &aux, int left, int mid, int right) {

  long int swaps = 0;

  int i = left, j = mid, k = left;

  while (i < mid && j <= right) {

    if (v[i] <= v[j]) {
      aux[k] = v[i];
      k++, i++;
    } else {
      aux[k] = v[j];
      k++, j++;
      swaps += mid - i;
    }
  }
  while (i < mid) {
    aux[k] = v[i];
    k++, i++;
  }

  while (j <= right) {
    aux[k] = v[j];
    k++, j++;
  }

  while (left <= right) {
    v[left] = aux[left];
    left++;
  }

  return swaps;
}

int count_swaps(vector<int> &v, vector<int> &aux, int left, int right) {
  long int swaps = 0;
  if (left < right) {
    int mid = left + (right - left) / 2;

    swaps += count_swaps(v, aux, left, mid);
    swaps += count_swaps(v, aux, mid + 1, right);
    swaps += merge(v, aux, left, mid + 1, right);
  }
  return swaps;
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
    vector<int> v(m);
    INPUT_VEC(v);
    vector<int> aux = v;
    // cout << count_swaps(v, aux, 0, v.size() - 1) << endl;
    cout << "Optimal train swapping takes "
         << count_swaps(v, aux, 0, v.size() - 1) << " swaps." << endl;
  }

  return 0;
}
