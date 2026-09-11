#include <iostream>
#include <queue>

#define u16 short unsigned

using namespace std;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);

  u16 n;
  while (1) {
    cin >> n;
    switch (n) {
    case 0:
      return 0;
    case 1:
      cout << "Discarded cards: \nRemaining card: 1 \n";
      continue;
    case 2:
      cout << "Discarded cards: 1 \nRemaining card: 2 \n";
      continue;
    case 3:
      cout << "Discarded cards: 1, 3 \nRemaining card: 2 \n";
      continue;
    }
    cout << "Discarded cards: ";
    for (u16 card = 1; card <= n; card += 2)
      cout << card << ", ";
    queue<u16> q;
    for (u16 card = 2; card <= n; card += 2)
      q.push(card);
    if (n % 2) {
      q.pop();
      q.push(2);
    }
    while (q.size() > 2) {
      cout << q.front() << ", ";
      q.pop();
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    q.pop();
    cout << "\nRemaining card: " << q.front() << endl;
  }
}
