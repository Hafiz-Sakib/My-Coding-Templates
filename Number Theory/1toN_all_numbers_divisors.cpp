// Bismillahir Rahmanir Rahim
/*

string author;
author = Hafiz_Sakib;

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e8 + 123;

vector<vector<ll>> Divisors(mx);

void OneToNDivisors(ll n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            Divisors[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";

        for (auto u : Divisors[i])
        {
            cout << u << ' ';
        }

        cout << endl;
    }
}

int main()
{
    OneToNDivisors(100);
    return 0;
}
