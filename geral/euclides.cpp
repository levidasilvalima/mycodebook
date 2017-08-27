#include<bits/stdc++.h>

using namespace std;

pair<int, int> pii;

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b, a%b);
}

pair<int, int> ee(int a, int b){

	if(b == 0) return make_pair(1, 0);
	
	pii=ee(b, a%b);
	
	return make_pair(pii.second, pii.first-((a/b)*pii.second));
}

int x, y;

int main(){
	while(cin >> x >> y){
		cout << x << ' ' << y << " = " << mdc(x, y) << endl;
		pii=ee(x,y);
		if(mdc(x, y) == 1){
			cout << "inverso : " << ((pii.first)+y)%y << endl;
			cout << "produto pelo inverso : " <<(((((pii.first)+y)%y)*x)%y+y)%y << endl;
		}
		
	}
	return 0;
}
