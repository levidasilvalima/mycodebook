#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
//#define left(x) (x << 1)
//#define right(x) ((x << 1) + 1)
//#define mid(a, b) ((a + b) >> 1)

using namespace std;

const int neutral = 0; //comp(neutral, x) = x
int comp(int a, int b) {
	return a + b;
}

int left(int x) {
	return x << 1;
}
int right(int x) {
	return (x << 1) + 1;
}
int mid(int a, int b) {
	return (a + b) >> 1;
}

vi a, tree, lazy;

void build(int u, int l, int r) {
	if(l == r) {
		tree[u] = a[l];
		return;
	}
	build(left(u), l, mid(l, r));
	build(right(u), mid(l, r) + 1, r);
	tree[u] = comp(tree[left(u)], tree[right(u)]);	
}

void push(int u, int l, int r) {
	tree[u] += (r - l + 1) * lazy[u]; //RSQ
//	tree[u] += lazy[u]  // RMQ
	if(l != r) {
		lazy[left(u)] += lazy[u];
		lazy[right(u)] += lazy[u];
	}
	lazy[u] = 0;
}

void update(int u, int i, int j, int l, int r, int value) {
	push(u, i, j);
	if(i > r || j < l) return;
	if(l <= i && j <= r) {
		lazy[u] = value;
		push(u, i, j);
	}
	else {
		update(left(u), i, mid(i, j), l, r, value);
		update(right(u), mid(i, j) + 1, j, l, r, value);
		tree[u] = comp(tree[left(u)], tree[right(u)]);
	}
}

int query(int u, int i, int j, int l, int r) {
	push(u, i, j);
	if(i > r || j < l) return neutral;
	if(l <= i && j <= r) return tree[u];

	int lans = query(left(u), i, mid(i, j), l, r);
	int rans = query(right(u), mid(i, j) + 1, j, l, r);
	
	return comp(lans, rans);
}

int q, size;

int main() {
	size = 5;
	a = {1, 1, 2, 3, 5};
	tree.assign(4 *(size + 1), neutral);
	lazy.assign(4 *(size + 1), 0);
	build(1, 0, size - 1);
	
	q = query(1, 0, size - 1, 0, size - 1);
	
	cout << q << endl; // q = 12

	update(1, 0, size - 1, 0, size - 1, 1);
	
	q = query(1, 0, size - 1, 0, size - 1);
	
	cout << q << endl; // q = 17
	
}
