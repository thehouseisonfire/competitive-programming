using this template, solve this problem

// TEMPLATE

#include <iostream>

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

// cin >> n;
// cin.ignore();
// getline(cin, str);
// str.clear();

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  return 0;
}

// PROBLEM
Uma equipe de pesquisadores está desenvolvendo uma nova tecnologia para economizar tempo ao digitar mensagens de texto em dispositivos móveis. Eles estão trabalhando em um novo modelo que tem um teclado completo, assim os usuários podem digitar qualquer letra pressionando a tecla correspondente. Desta forma, um usuário precisa pressionar P teclas para digitar uma palavra de comprimento P.

No entanto, isto não é suficientemente rápido. A equipe vai montar um dicionário de palavras comuns que um usuário pode digitar. O objetivo é reduzir o número médio de teclas pressionadas necessárias para digitar palavras que constam no dicionário. Durante a digitação de uma palavra, sempre que houver apenas uma possibilidade para a seguinte letra, o sistema de telefone celular irá introduzí-la automaticamente, sem a necessidade de digitação. Para ser mais preciso, o comportamento do sistema de telefone celular irá ser determinado pelas seguintes regras:

1. O sistema nunca irá adivinhar a primeira letra de uma palavra, ou seja, para a primeira letra sempre terá que ser pressionada a tecla correspondente.

2. Se uma sucessão não-vazia de letras c1c2...cn for introduzida, e houver uma letra c tal que cada palavra no dicionário que começa com c1c2...cn também começa com c1c2 ... cnc, em seguida, o sistema coloca a entrada c automaticamente, sem a necessidade de uma combinação de teclas. Caso contrário, o sistema aguarda o usuário.

Por exemplo, se o dicionário é composto das palavras "hello", "hell", "heaven" e "goodbye", e o usuário pressiona "h", o sistema colocará a letra "e" automaticamente, porque cada palavra que começa com "h" também começa com "he". No entanto, uma vez que existem palavras que começam com "hel" e com "hea", o sistema precisa agora esperar a próxima digitação do usuário. Se o usuário pressionar então o "l", obtendo-se a palavra parcial "hel", o sistema de entrada incluirá um segundo "l" automaticamente. Quando se tem o "hell" como entrada, o sistema não pode supor nada, porque é possível que a palavra terminou, ou também é possível que o usuário pode querer pressionar "o" para obter "hello". Desta forma, para digitar a palavra "hello" o usuário precisa de três teclas, "hell" exige duas e "heaven" também requer duas, porque quando a entrada é "hea" o sistema pode colocar automaticamente o restante da palavra aplicando repetidamente a segunda regra. Da mesma forma, a palavra "goodbye" precisa de apenas uma tecla, porque depois de pressionar a inicial "g", a sistema irá preencher automaticamente a palavra inteira. Neste exemplo, o número médio de teclas necessário digitar uma palavra no dicionário é, então, (3 + 2 + 2 + 1) / 4 = 2.00.

Dado um determinado dicionário, sua tarefa então é calcular o número médio de teclas necessárias para escrever uma palavra no dicionário com o novo sistema para celular desenvolvido pelos pesquisadores.

Entrada
Cada caso de teste é descrito por várias linhas. A primeira linha contém um número inteiro N representando o número de palavras no dicionário (1 ≤ N ≤ 105 ). Cada uma das próximas N linhas contém uma string não-vazia de no máximo 80 letras minúsculas do alfabeto inglês, representando uma palavra no dicionário. Dentro de cada caso de teste todas as palavras são diferentes, e a soma dos comprimentos de todas as palavras é, no máximo, 106.
