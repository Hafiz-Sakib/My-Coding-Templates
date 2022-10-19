// Complexity O(n)
const int MX = 1e6;
ll fact[MX+5], inv[MX+5];
ll bigmod(ll a, ll p, ll M)
{
    // If 'M' is a prime number, then we can speed up it just by calculating "a^(p%(M-1))";
	p %= (M-1);
	
    ll result = 1LL;
    while(p>0LL){
        if(p&1LL) result = result * a % M;
        a = a * a % M;
        p>>=1LL;
    }
    return result;
}
ll inverse(ll a, ll M){
    if(gcd(a, M)==1) return bigmod(a, M-2, M) % M; // (ax)%M = 1
    return 1;
}
void factorial()
{
	fact[0] = fact[1] = 1;
	for(ll K=1; K<=MX; K++) fact[K] = fact[K-1] * K % mod;
	
	inv[MX] = inverse(fact[MX], mod);
	for(ll K=MX-1; K>=1; K--) inv[K] = inv[K+1] * (K+1) % mod;
	inv[0] = 1;
}

// function call ...
factorial();
cout << (fact[18]*inv[5]%mod)*inv[13]%mod << "\n";
