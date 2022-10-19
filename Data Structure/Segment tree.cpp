#include <bits/stdc++.h>
using namespace std;

int sum[400001], num[100001];
// keep num size 4*n;

/// Building segment trees...
void build(int at, int l, int r)
{
	sum[at] = 0;
	
	if(l == r){
		// keeping the sum...
		// Or, maybe other queries...
		sum[at] = num[l];
		
		return;
	}
	
	int mid = (l+r)/2;
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	// keeping the sum...
	// Or, maybe other queries...
	sum[at] = sum[at*2] + sum[at*2+1];
}

/// Updating segment tree...
void update(int at, int l, int r, int idx, int num)
{
	if(l == r){
		sum[at] += num;
		return;
	}
	
	int mid = (l+r)/2;
	
	// instead of if-else
	// we can use 
	// if(pos < L || R < pos) return;
	if(pos<=mid) update(at*2, l, mid, idx, num);
	else update(at*2+1, mid+1, r, idx, num);
	
	sum[at] = sum[at*2] + sum[at*2+1];
}


/// Making queries in segment tree...
int query(int at, int l, int r, int L, int R)
{
	// query from l to r.
	if(R < l || L > r) return 0;
	if(L <= l && r <= R) return sum[at];
	
	int mid = (l+r)/2;
	int x = query(at*2, l, mid, L, R);
	int y = query(at*2+1, mid+1, r, L, R);
	
	return x+y;
}

int main()
{
	int n, u, q, pos, value, l, r;
	
	// Input data(s).
	cin >> n;
	for(int K=1; K<=n; K++) cin >> num[K];
	
	// build...
	build(1, 1, n);
	
	// update...
	
	# handle indexes for 0 based ones. ( This Tamplate is 1 based...)
	# consider overflow for sum.
	for(int K=1; K<=4*n; K++) cout << sum[K] << ' ';
	cout << "\n";
	
	cin >> u;
	while(u--){
		cin >> pos >> value;
		update(1, 1, n, pos, value);
	}
	
	// queries...
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << "\n";
	}
	
	return 0;
}
