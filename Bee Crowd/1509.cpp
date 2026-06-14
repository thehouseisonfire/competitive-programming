#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Função para calcular o número de maneiras de formar a palavra-alvo
int countWays(const string &target, const vector<string> &words) {
  int n = target.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1; // Há 1 maneira de formar a palavra vazia

  // Para cada posição na palavra-alvo
  for (int i = 0; i < n; i++) {
    // Se já existe uma maneira de chegar até aqui
    if (dp[i] > 0) {
      // Tentar encaixar cada palavra conhecida a partir da posição i
      for (const string &word : words) {
        int len = word.size();
        if (i + len <= n && target.substr(i, len) == word) {
          dp[i + len] = (dp[i + len] + dp[i]) % MOD;
        }
      }
    }
  }

  // Retorna o número de maneiras de formar a palavra-alvo inteira
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int D;
  while (cin >> D) {
    vector<string> words(D);

    // Ler as palavras conhecidas
    for (int i = 0; i < D; i++) {
      cin >> words[i];
    }

    int U;
    cin >> U;

    // Processar cada palavra-alvo
    for (int i = 0; i < U; i++) {
      string target;
      cin >> target;
      // Para cada palavra-alvo, calcular o número de maneiras de formá-la
      cout << countWays(target, words) << '\n';
    }
  }

  return 0;
}
