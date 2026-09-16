#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> speeds(n);
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  for (int i = 0; i < n; i++)
    cin >> speeds[i];

  for (int i = 0; i < n; i++)
    pq.push({0, i});

  ll maxx = 0;

  for (int i = 0; i < m; i++) {
    int items;
    cin >> items;

    auto [time, id] = pq.top();
    pq.pop();

    time += speeds[id] * items;
    maxx = max(maxx, time);

    pq.push({time, id});
  }

  cout << maxx << endl;
}
