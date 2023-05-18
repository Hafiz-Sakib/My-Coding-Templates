
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e8;
typedef long long int ll;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

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
    PrimeFactorization(1000);

    for (auto u : PrimeFactors)
    {
        cout << u << ' ';
    }
    cout << endl;
    return 0;
}
