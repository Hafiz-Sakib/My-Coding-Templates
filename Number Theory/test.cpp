// Bismillahir Rahmanir Rahim
/*

string author;
author = Hafiz_Sakib;

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e8;
vector<int> primes = {2, 3, 5, 7, 11, 17, 23, 29};

vector<vector<int>> OneToNPrimeFactors(mx);

void OneToNPrimeFactorization(int n)
{
    for (auto p : primes)
    {
        for (int i = p; i <= n; i += p)
        {
            OneToNPrimeFactors[i].push_back(p);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto u : OneToNPrimeFactors[i])
        {
            cout << u << ' ';
        }
        cout << endl;
    }
}

int main()
{
    OneToNPrimeFactorization(10);
    return 0;
}
