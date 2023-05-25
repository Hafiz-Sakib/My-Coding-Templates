#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e8;
#define endl "\n";

#define Boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

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

ll SODFormula(ll n)
{
    ll ans = 1;
    for (auto p : primes)
    {
        if (1LL * p * p > n)
        {
            break;
        }
        else if (n % p == 0)
        {
            ll CurrentSum = 1, PowerOfPrime = p;
            while (n % p == 0)
            {
                PowerOfPrime *= p;
                n /= p;
            }
            ans *= ((PowerOfPrime - 1) / (p - 1));
        }
    }
    if (n > 1)
    {
        ans *= (n + 1);
    }
    return ans;
}

void Boom()
{
    ll n;
    cin >> n;
    cout << SODFormula(n) << endl;
}

int main()
{
    sieve(1e6);
    Boost;
    int t;
    cin >> t;
    while (t--)
    {
        Boom();
    }
    return 0;
}
