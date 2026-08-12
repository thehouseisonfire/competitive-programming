#include <iostream>

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    for (size_t j = 0; j < k; j++) {
      int f;
      std::cin >> f;
      switch (f) {
      case 1:
        std::cout << "Rolien" << std::endl;
        break;
      case 2:
        std::cout << "Naej" << std::endl;
        break;
      case 3:
        std::cout << "Elehcim" << std::endl;
        break;
      case 4:
        std::cout << "Odranoel" << std::endl;
        break;
      }
    }
  }
  return 0;
}
