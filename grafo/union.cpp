#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1000123 

using namespace std;

int i, n, m, pai[MAXN], tam[MAXN];

int id(int n){
	if(n!=pai[n]) return pai[n]=id(pai[n]);
	return pai[n];
}

void join(int u, int v){
	u=id(u), v=id(v);
	if(u==v) return;
	if(tam[u]<tam[v]) swap(u, v);
	pai[v]=u;
	tam[u]+=tam[v];
}

int main(){_
	while(cin >> n >> m){
		for(i=0; i<=n; i++) tam[i]=1, pai[i]=i;
	}
	return 0;
}
