#include <algorithm>
#include <iostream>
#include <map>
#include <set>
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

struct Country {
  u16 golds = 0;
  u16 silvers = 0;
  u16 bronzes = 0;
};

// struct comp {
//   bool operator()(const pair<string, Country> &l,
//                   const pair<string, Country> &r) const {
//     return l.second.golds != r.second.golds ? l.second.golds > r.second.golds
//            : l.second.silvers != r.second.silvers
//                ? l.second.silvers > r.second.silvers
//            : l.second.bronzes != r.second.bronzes
//                ? l.second.bronzes > r.second.bronzes
//                : l.first.compare(r.first) < 0;
//   }
// };

bool cmp(const pair<string, Country> &l, const pair<string, Country> &r) {
  return l.second.golds != r.second.golds ? l.second.golds > r.second.golds
         : l.second.silvers != r.second.silvers
             ? l.second.silvers > r.second.silvers
         : l.second.bronzes != r.second.bronzes
             ? l.second.bronzes > r.second.bronzes
             : l.first.compare(r.first) < 0;
  // if (l.second.golds != r.second.golds)
  //   return l.second.golds > r.second.golds;
  // else if (l.second.silvers != r.second.silvers)
  //   return l.second.silvers > r.second.silvers;
  // else if (l.second.bronzes != r.second.bronzes)
  //   return l.second.bronzes > r.second.bronzes;
  // else
  //   return l.first.compare(r.first);
}

void solution(map<string, Country> &map) {

  vector<pair<string, Country>> countries;
  countries.reserve(63);
  for (auto itr = map.begin(); itr != map.end(); ++itr)
    countries.push_back(*itr);
  // for (auto cnt : countries) {
  //   cout << cnt.first << ": " << cnt.second.golds << " " <<
  //   cnt.second.silvers
  //        << " " << cnt.second.bronzes << endl;
  // }
  cout << "Quadro de Medalhas\n";
  sort(countries.begin(), countries.end(), cmp);
  for (auto cnt : countries) {
    cout << cnt.first << ": " << cnt.second.golds << " " << cnt.second.silvers
         << " " << cnt.second.bronzes << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string ignore;
  map<string, Country> map;
  while (cin >> ignore) {
    string gold, silver, bronze;
    cin >> gold >> silver >> bronze;
    map[gold].golds++;
    map[silver].silvers++;
    map[bronze].bronzes++;
  }
  solution(map);
  return 0;
}
