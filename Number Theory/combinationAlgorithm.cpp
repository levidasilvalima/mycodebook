#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

// Algoritmo para calcular o numero de
// combinacoes de C(n, k).
// C(n, k) = n!/(k!(n - k)!)

long long combinations(long long n, long long k) {
	long long combination = 1LL;
	for (int i = 1LL; i <= k; i += 1LL) {
		combination *= (n - i + 1LL);
		// como sabemos i numero consecutivos
		// multiplicados sempre sao divisiveis por i
		// fazemos:
		combination /= i;
	}
	return combination;
}

long long n, k;

int main() {_
	while (scanf("%lli %lli", &n, &k) == 1) {
		printf("%lli\n", combinations(n, k));
	}
	return 0;
}
