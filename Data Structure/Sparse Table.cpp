// sparse table
const int MX = 2e5;
const int lg = 20;
int spt[lg+1][MX+5], ara[MX+5];

int n;

void build_spt()
{
    for(int K = 0; K < n; K++) spt[0][K] = ara[K];

    for(int K = 1; K < lg; K++){
        for(int L = 0; L < n; L++){
            if(L+(1<<K) > n) break;
            spt[K][L] = spt[K-1][L] + spt[K-1][L+(1<<(K-1))];
        }
    }
}
int get(int l, int r)
{
    int ans = 0;

    for(int K = lg; K >= 0; K--){
        if(l+(1<<K)-1 <= r){
            ans += spt[K][l];
            l += (1<<K);
        }
    }
    // For idempodent functions, we can calculate it in O(n)
    // then, ans = gcd(spt[K-1][l], spt[K-1][l+(1<<(K-1))]);

    return ans;
}
