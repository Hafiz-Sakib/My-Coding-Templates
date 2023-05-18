#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e8;

vector<int> primes = {2, 3, 5, 7, 11};

vector<vector<int>> PrimeFactors(mx);

void PrimeFactorization(int n)
{
    // Can Sieve First
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
    PrimeFactorization(15);

    // 1 to 15 all numbers Prime Factorization

    return 0;
}
