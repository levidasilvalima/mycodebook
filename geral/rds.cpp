#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define MAXN 1000123

int n, m, i, f[MAXN], s, ans, v;

using namespace std;

int main(){_
	while(cin >> n >> m && n || m){
		for(s=0, f[0]=1; n--; ){
			cin >> v;
			s+=(s+v)%m;
			f[s]++;
		}
		for(ans=i=0; i<m; i++){
			ans+=((f[i]*(f[i]-1))/2);
			f[i]=0;
		}
		cout << ans << endl;
	}
	return 0;
}
