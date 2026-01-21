#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define MAXN 1000123
#define MAXM 1000123

using namespace std;

int n, m, i, up[MAXN], rank[MAXN], ans;

struct aresta {
	int u, v, w;
};

aresta a[MAXM];

int cmp(aresta a, aresta b) {
	return a.w < b.w;
}

int id(int n) {
	if (n != up[n]) {
		return up[n] = id(up[n]);
	}
	return up[n];
}

void join(int u, int v) {
	u = id(u), v = id(v);
	if (rank[u] < rank[v]) {
		swap(u, v);
	}
	up[v] = u;
	rank[u] += rank[v];
}

void init(int n) {
	for (i = 0; i < n; i++) {
		up[i] = i;
		rank[i] = 1;
	}
}

int main() {_
	while (cin >> n >> m) {
		init(n + 3);
		for (i = m; i--; ) {
			cin >> a[i].u >> a[i].v >> a[i].w;
		}
		sort(a, a + m, cmp);
		for (i = ans = 0; i < m; i++) {
			if (id(a[i].u) != id(a[i].v)) {
				join(a[i].u, a[i].v);
				ans += a[i].w;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
