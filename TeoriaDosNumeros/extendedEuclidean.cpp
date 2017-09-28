#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio();
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

// algoritmo de Euclides para calculo do mdc
// mmc(a, b) = a * (b / mdc(a, b))

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b, a % b);
}

// Euclides extendido resolve sistemas do tipo:
// Ax + By = mdc(A, B)
// Com a aplicacao de calcular o inverso modular
// de 'A' na base 'B' onde 'A' e 'B'
// precisam ser coprimos obviamente.
// A solucao parte do principio de que
// Ax + By = mdc(A, B) equivale a:
// Bx' + (A % B)y' = mdc(A, B) = Bx' + (A - B(A/B))y'.
// Apos a distribuicao, encontramos a equacao seguinte:
// Ay' + B(x' - (A / B)y') = mdc(A, B), portanto, seguindo a equivalencia temos:
// x = y' e y = x' - (A / B)y'.
// Recursivamente (A % B) se tornara '0'
// restando como solucao Bx' = mdc(A, B)
// onde, obviamente, B sera igual ao mdc(A, B), ou seja, s = [1, 0].
// Para socucao final onde queremos o 'x' e 'y'
// da primeira equacao, subiremos na rescursao
// a partir da equivalencia que encontramos anteriormente.

pii extendedEuclidean(int a, int b){
	if(b == 0) return pii(1, 0);

	ans = extendedEuclidean(b, a % b);

	return pii(ans.sc, ans.fs - ((a / b) * ans.sc));
}

int main(){
	while(scanf("%i %i", &a, &b) == 1){
		printf("mdc(%i, %i) == %i\n", a, b, mdc(a, b));
		pii ans = extendedEuclidean(a, b);
		if(mdc(a, b) == 1){
			printf("inverso de 'a' na base 'b' : %i\n", (ans.fs + b) % b);
			printf("produto de 'a' pelo inverso de 'a' na base 'b' : %i\n", (((ans.fs + b) % b) * x ) % b);
		}
	}
	return 0;
}
