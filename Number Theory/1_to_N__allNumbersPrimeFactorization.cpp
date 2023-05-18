#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e8;

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

vector<vector<int>> PrimeFactors(mx);

void PrimeFactorization(int n)
{
    for (auto p : primes)
    {
        for (int i = p; i <= n; i += p)
        {
            PrimeFactors[i].push_back(p);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto u : PrimeFactors[i])
        {
            cout << u << ' ';
        }
        cout << endl;
    }
}

int main()
{
    sieve(1e5);

    PrimeFactorization(1000);

    // 1 to 1000 all numbers Prime Factorization

    return 0;
}
