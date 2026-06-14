#include <iostream>

int solution();

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  float n, m;
  std::cin >> n >> m;
  std::cout << (n / m);
  return 0;
}
