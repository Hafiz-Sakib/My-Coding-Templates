#include <bits/stdc++.h>
using namespace std;

int n;
int a[10010], b[10010];
int bs(int h, int x) {
	int l = 1, ans = 0;
	
	while(l <= h) {
		int m = (l+h)>>1;
		
		if(x > a[b[m]]) { ans = m; l = m+1; }
		else h = m-1;
	}
	return ans+1;
}

int lis() {
	int len = 0;
	int p[n];
	
	for(int i = 0; i < n; ++i) {
		int tmp = bs(len, a[i]);
		
		b[tmp] = i;
		p[i] = b[tmp-1];
		len = max(tmp, len);
	}
	
	int k = b[len];
	int s[len];
	for(int i = len-1; i >= 0; --i) {
		s[i] = a[k];
		k = p[k];
	}
	
	for(int i = 0; i < len; ++i) cout << s[i] << ' '; // prints answer array.
	cout << endl;
	
	return len;             // returns answer length();
}

int main(){
    cin >> n;
    for(int K=0; K<n; K++) cin >> a[K];
    
    int p = lis();          // answer length();
    cout << p << "\n";       
}

