
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e8;
typedef long long int ll;

bitset<mx> is_prime;
vector<int> primes;

void sieve(int n)
{

    for (int i = 3; i <= n; i += 2)
    {
        is_prime[i] = 1;
    }

    for (int i = 3; (i * i) <= n; i += 2)
    {
        if (is_prime[i])
        {
            for (int j = (i * i); j <= n; j += (i + i))
            {
                is_prime[j] = 0;
            }
        }
    }

    is_prime[1] = 0;
    is_prime[2] = 1;
    primes.push_back(2);

    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
vector<ll> PrimeFactors;

void PrimeFactorization(ll n)
{
    PrimeFactors.clear();
    // Call sieve function first for access primes till n
    for (auto p : primes)
    {
        if (1LL * p * p > n)
        {
            break;
        }
        else if (n % p == 0)
        {
            while (n % p == 0)
            {
                PrimeFactors.push_back(p);
                n /= p;
            }
        }
    }
    if (n > 1)
    {
        PrimeFactors.push_back(n);
    }
}
int main()
{
    sieve(12345);

    PrimeFactorization(1000);

    for (auto u : PrimeFactors)
    {
        cout << u << ' ';
    }
    cout << endl;
    return 0;
}
