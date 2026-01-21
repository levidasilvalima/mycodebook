#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
// Algoritmo para calcular A^B mod M
// em complexidade O(log B)

using namespace std;

// O Algoritmo usa o principio de potencia de potencia
// onde a cada iteracao elevamos a base interna ao
// quadrado e dividimos a potencia externa. Quando nos
// deparamos com uma potencia impar, dividimos em uma
// multiplicacao de potencia para que um dos fatores
// da multiplicacao tenha potencia par.

int fastExponentiation(int base, int expo, int m) {
	int res = 1; // inicializa o resultado
	base = base % m; // caso a base seja maior que o m
	while (expo > 0) {
		// se for impar quer dizer que
		// minha base atual tem que ser
		// aumentada em um
		if (expo & 1) {
			res = (res * base) % m;
		}

		expo = expo >> 1; // divide o expoente pela metade
		base = (base * base) % m; //acumula para
	}
	return res;
}

int a, b, c;

int main() {_
	while (scanf("%i %i %i", &a, &b, &c) == 1) {
		printf("%i ^ %i mod %i == %i\n", a, b, c, fastExponentiation(a, b, c));
	}
	return 0;
}
