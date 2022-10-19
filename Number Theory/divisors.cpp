// Number of divisors...
// Euler's totient function...

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
vector<pair<int, int> > divisors;
void divs(int n) {
	// O(sqrt(n))
	int cnt, tot=1, i;
	
	for(i=0; i<(int)primes.size() && (primes[i]*primes[i])<=n; i++) {
		if(n%primes[i]==0) {
			cnt=1;
			
			while(n%primes[i]==0) {
				n/=primes[i];
				cnt++;
			}
			
			divisors.push_back(make_pair(primes[i], cnt-1));
			tot*=cnt;
		}
	}
	
	if(n>1) {
		tot*=2;
		divisors.push_back(make_pair(n, 1));
	}
	
	printf("Number of divisors %d\n", tot);
	for(i=0; i<(int)divisors.size(); i++)
		printf("%d %d\n", divisors[i].first, divisors[i].second);
}

// Number of divisors...
ll NOD(int n)
{
	ll ans = 1;
	
	for(int K=0; K<sz(divisors); K++){
		ans *= (ll)(divisors[K].se+1);
	}
	
	return ans;
}
//Sum of divisors...
ll SOD(int n)
{
	ll ans = 1, cnt;
	for(int K=0; K<sz(divisors); K++){
		cnt = divisors[K].fi;
		while(divisors[K].se--) cnt *= (ll)divisors[K].fi;
		
		ans *= (ll)(cnt-1)/(divisors[K].fi-1);
	}
	return ans;
}


int main()
{
	sieve(root(n));
	
	divs(n);
	
	cout << NOD(n) << ' ' << SOD(n) << "\n";
	
	return 0;
}
