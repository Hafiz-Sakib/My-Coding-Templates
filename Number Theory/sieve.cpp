// sieve :- prime number generator;
// 0 for prime, 1 for not prime;

vector<int> primes;
vector<bool> mark(1000002);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

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


// Block Sieve :
// Block size, S = 1e4 to 1e5.
// Output: returns number of primes

int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}



// Segmented Sieve:
// Output: prime list in range {L, R}; (R-L+1) <= 1e7 && R <= 1e12;
vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}



// Bitwise - sieve :- prime number generator;
// 0 for prime, 1 for not prime;  >> Not sure ...

#define MX 1000000000

int marked[MX/64+2];
vector<int> primes;

#define mark(x) marked[x>>6] |= (1<<((x&63)>>1))
#define check(x) (marked[x>>6] & (1<<((x&63)>>1)))

bool isPrime(int x) { return (x>1) && ((x==2) || ((x&1) && (!(check(x))))); }

void seive(int n)
{
    int i, j;
    primes.push_back(2);
    for(i=3; i*i<=n; i+=2){
        if(!check(i)){
            primes.push_back(i);
            for(j=i*i; j<=n; j+=i<<1) mark(j);
        }
    }
}



// another sieve...
// 1 for prime and 0 for not-prime...
ll _sieve_size;
bitset<10000010> bs;
void sieve(ll upperbound)
{
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i=2; i<=_sieve_size; i++){
		if(bs[i]){
			for(ll j=i*i; j<=_sieve_size; j+=i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}
bool isPrime(ll n)
{
	if(n<=_sieve_size) return bs[n];
	
	for(int i=0; i<(int)primes.size(); i++){
		if(n%primes[i]==0) return false;
	}
	return true;
}

sieve(10000000);
