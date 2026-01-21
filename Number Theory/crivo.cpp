#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100123

using namespace std;

int i, j, n, tam;
bitset <MAXN> ehcomp;

void crivo() {
	ehcomp.reset();
	ehcomp.set(1);
	for (i = 3; i * i <= MAXN; i += 2) {
		if (!ehcomp[i]) { // se ele for primo
			for (j = i * i; j < MAXN; j += i) {
				//marca todos os multiplos dele
				if (!ehcomp[j]) {
					ehcomp.set(j);
				}
			}
		}
	}
}

int main() {_
	crivo();
	while (cin >> n) {
		if (!(n % 2) && (n != 2)) {
			cout << "not prime\n";
		} else {
			cout << (ehcomp[n] ? "not prime" : "prime") << endl;
		}
	}
	return 0;
}
