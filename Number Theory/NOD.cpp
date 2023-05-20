#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int NOD(ll n)
{
    // This function will return how many divisors in (n) using Prime Factorization
    int ans = 1;
    // Call Sieve Function First
    for (auto p : primes)
    {
        if (1LL * p * p > n)
        {
            break;
        }
        else if (n % p == 0)
        {
            int cnt = 1;
            while (n % p == 0)
            {
                n /= p;
                cnt++;
            }
            ans *= cnt;
        }
    }
    if (n > 1)
    {
        ans *= 2;
    }
    return ans;
}

int main()
{

    return 0;
}
