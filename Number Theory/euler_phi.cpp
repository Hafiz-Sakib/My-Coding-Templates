#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007

#define Boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const int mx = 1e6;
bitset<mx> is_prime;
vector<int> primes;

void Sieve(int n)
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

int EulerPhi(int n)
{
    int ans = n;
    for (auto p : primes)
    {
        if (p * 1LL * p > n || n == 0)
        {
            break;
        }
        if (n % p == 0)
        {
            ans /= p;
            ans *= (p - 1);
            while (n % p == 0)
            {
                n /= p;
            }
        }
    }

    if (n > 1)
    {
        ans /= n;
        ans *= (n - 1);
    }

    return ans;
}

int main()
{
    Boost;
    Sieve(1e6);
    /*
        Euler Phi ফাংশন দ্বারা বুঝায় যে ১ থেকে n পর্যন্ত n এর কয়টা কো-প্রাইম আছে?
        a,b যদি কো-প্রাইম হয় তবে তাদের gcd(a,b) = 1 হবে ।

        Time Complexity : sqrt(n)/ln(sqrt(n)) --> Similar To Prime Factorization
    */

    int n;
    cin >> n;
    cout << EulerPhi(n) << endl;
    return 0;
}
