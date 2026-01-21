#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1000123 

using namespace std;

int i, n, m, up[MAXN], rank[MAXN];

int id(int n) {
	if (n != up[n]) {
		return up[n] = id(up[n]);
	}
	return up[n];
}

void join(int u, int v) {
	u = id(u), v = id(v);
	if (u == v) {
		return;
	}
	if (rank[u] < rank[v]) {
		swap(u, v);
	}
	up[v] = u;
	rank[u] += rank[v];
}

int main() {_
	while (cin >> n >> m) {
		for (i = 0; i <= n; i++) {
			rank[i] = 1;
			up[i] = i;
		}
	}
	return 0;
}
