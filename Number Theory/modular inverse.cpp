// When M is prime...
// Whwn A ans M are co-prime.
// complexity O(logM)
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

// when M is not prime...
// Whwn A and M are co-prime.
// complexity O(log10A+log10B) 
ll modInv(ll a, ll m) {
    int x, y;
    ext_gcd(a, m, &x, &y);
 
    // Process x so that it is between 0 and m-1
    x %= m;
    if (x<0LL) x += m;
    return x;
}
