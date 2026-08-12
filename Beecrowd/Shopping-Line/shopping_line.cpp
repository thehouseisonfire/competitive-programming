#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define u8 unsigned char
#define u16 short unsigned
#define u32 unsigned
#define i16 short int

#define ASCII_NUMBER_OFFSET 48
#define ASCII_UPPERCASE_OFFSET 65
#define ASCII_LOWERCASE_OFFSET 97

int solution();

int main(int argc, char *argv[]) {
  using namespace std;
  typedef pair<u16, u16> pu;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int nclients, ncashiers;
  // string cashier_speeds, client_weights;
  // priority_queue<pu, vector<pu>, greater<pu>> min_prio_q;
  //
  // cin >> ncashiers >> nclients >> ws;
  // getline(cin, cashier_speeds);
  // getline(cin, client_weights);
  // u16 max = 0;
  // if (ncashiers >= nclients) {
  //   cout << "yeah";
  //   for (u16 i = 0; i < nclients; i += 2)
  //     if (max < client_weights[i])
  //       max = client_weights[i];
  //   cout << max << endl;
  //   return 0;
  // }
  // u16 i = 0;
  // // push all cashiers into the queue
  // for (u16 j = 0; j < ncashiers; i += 2) {
  //   min_prio_q.push(make_pair(
  //       client_weights[i] * (cashier_speeds[i] - ASCII_NUMBER_OFFSET), j));
  //   j++;
  // }
  // while (!min_prio_q.empty()) {
  //   auto p = min_prio_q.top();
  //   cout << p.second << " " << p.first;
  // }
  vector<u16> client_weights;
  vector<u16> cashier_speeds;
  priority_queue<u16> pq;
  for (u16 i = 0; i < ncashiers; i++) {
    u16 aux;
    cin >> aux;
    cashier_speeds.push_back(aux);
    pq.push(i);
  }
  for (u16 i = 0; i < nclients; i++) {
    u16 aux;
    cin >> aux;
    cashier_speeds.push_back(aux);
  }
  priority_queue<pu, vector<pu>, greater<pu>> min_prio_q;
  u16 i = 0;
  for (; i < ncashiers; i++) {
    min_prio_q.push(make_pair(cashier_speeds[i] * client_weights[i], i));
  }
  return 0;
}
