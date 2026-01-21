#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 20
#define MAXM (1<<20)
#define mk make_pair
#define fs first
#define sc second
#define INF (int)1e9

using namespace std;

typedef pair<int, int> pii;

int adj[MAXN][MAXN], ans, memo[MAXN][MAXM];

int x, y, n, cont = 0;
pii no[MAXN];

int tsp(int u, int vis) {
	if (vis == ((1 << n) - 1)) {
		return adj[u][0];
	}
	
	if (memo[u][vis] != -1) {
		return memo[u][vis];
	}
	
	int best = INF;
	for (int v = 0; v < n; v++) {
		if (!(vis & (1 << v))) {
			int next_vis = (vis | (1 << v));
			int x = tsp(v, next_vis) + adj[u][v];
			best = min(best, x);
		}
	}
	return memo[u][vis] = best;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << (n + 1)); j++) {
			memo[i][j] = -1;
		}
	}	
}

int main() {_
	while (scanf("%d", &n) != EOF) {
		init(n + 2);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {	
				scanf("%i", &adj[i][j]);
			}
		}
		ans = tsp(0, 1);
		printf("%i\n", ans);
	}
	return 0;
}
