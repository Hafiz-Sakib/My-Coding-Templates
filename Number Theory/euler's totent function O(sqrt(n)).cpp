// Euler's Totient

vector<int> primes;
bitset<100005> mark;
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;
    
    mark.reset();
    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
int EulerT(int n) {
    if(n==1)return 0;
    int toi=n, i;
    for(i=0; i<(int)primes.size() && (primes[i]*primes[i])<=n; i++) {
        if(n%primes[i]==0) {
        while(n%primes[i]==0) n/=primes[i];
            toi-=toi/primes[i];
        }
    }
    if(n>1) toi-=toi/n;
    return toi;
}
