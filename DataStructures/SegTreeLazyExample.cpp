// URI 1500 - Horrible Queries
// https://www.urionlinejudge.com.br/judge/en/problems/view/1500
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define mid(a, b) ((a + b) >> 1)
#define comp(a, b) (a + b)
#define MAX 1000123
#define OUT 0
#define ll long long
#define vi vector<ll>

using namespace std;

vi tree, a, lazy;

int size;

ll build(int u, int l, int r) {
	if(l == r) return tree[u] = a[l];
	build(left(u), l, mid(l, r));
	build(right(u), mid(l, r) + 1, r);
	
	return tree[u] = comp(tree[left(u)], tree[right(u)]);
}

void push(int u, int l, int r) {
	if(lazy[u] == OUT) return;
	tree[u] += lazy[u] * (r - l + 1);
	if(l != r) {
		lazy[left(u)] += lazy[u];
		lazy[right(u)] += lazy[u];
	}
	lazy[u] = OUT;
}

ll update(int u, int i, int j, int l, int r, ll value) {
	push(u, i, j);
	if(i > r || j < l) return OUT;
	if(l <= i && j <= r) {
		lazy[u] += value;
		push(u, i, j);
		return tree[u];
	}	
	update(left(u), i, mid(i, j), l, r, value);
	update(right(u), mid(i, j) + 1, j, l, r, value);
	return tree[u] = comp(tree[left(u)], tree[right(u)]);
}

ll update(int l, int r, int value) {
	return update(1, 1, size, l, r, value);
}

ll query(int u, int i, int j, int l, int r) {
	push(u, i, j);
	if(i > r || j < l) return OUT;
	if(l <= i && j <= r) return tree[u];
	
	ll lans = query(left(u), i, mid(i, j), l, r);
	ll rans = query(right(u), mid(i, j) + 1, j, l, r);
	
	return comp(lans, rans);
	
}

ll query(int l, int r) {
	return query(1, 1, size, l, r);
}

int n, T, m;

int op, r, l, v;

int main() {_
	cin >> T;
	while(T--) {
		cin >> n >> m;
		size = n;
		a = vi(size + 1, 0);
		tree = vi(4 * (size + 1), 0);
		lazy = vi(4 * (size + 1), OUT);
		build(1, 1, size);
		while(m--) {
			cin >> op;
			if(op) {
				cin >> l >> r;
				cout << query(l, r) << endl;
			} 
			else {
				cin >> l >> r >> v;
				update(l, r, v);
			}
		}
	}
	return 0;
}
