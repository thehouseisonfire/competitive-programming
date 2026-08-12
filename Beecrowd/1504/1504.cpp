#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura para armazenar as coordenadas das casas
struct House {
    int x, y;
};

// Função para verificar se podemos construir a ferrovia
bool canBuildRailroad(const vector<House>& houses) {
    int N = houses.size();

    // Se o número de casas é ímpar, não podemos dividir igualmente
    if (N % 2 != 0) {
        return false;
    }

    // Ordenamos as casas pelas coordenadas x e y separadamente
    vector<int> X, Y;
    for (const auto& house : houses) {
        X.push_back(house.x);
        Y.push_back(house.y);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    // Precisamos que o ponto médio da soma de X e Y seja o mesmo para que haja uma linha divisora
    // Os dois pontos centrais no eixo X e Y devem ser iguais
    int mid = N / 2;
    int sumX = X[mid - 1] + X[mid];
    int sumY = Y[mid - 1] + Y[mid];

    // Verificamos se os pontos centrais podem formar uma linha de simetria
    for (int i = 0; i < N / 2; ++i) {
        int symX = X[N - 1 - i] + X[i];
        int symY = Y[N - 1 - i] + Y[i];
        if (symX != sumX || symY != sumY) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        vector<House> houses(N);

        // Leitura das coordenadas das casas
        for (int i = 0; i < N; ++i) {
            cin >> houses[i].x >> houses[i].y;
        }

        // Verifica se é possível construir a ferrovia
        if (canBuildRailroad(houses)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
