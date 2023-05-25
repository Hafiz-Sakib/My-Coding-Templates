// Bismillahir Rahmanir Rahim
/*

string author;
author = Hafiz_Sakib;

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define Boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// SNOD in O(√n) Complexity

ll SNOD(ll n)
{
    ll ans = 0, u = sqrt(n);
    for (int i = 1; i <= u; i++)
    {
        ans += (n / i) - i;
    }
    ans *= 2;
    ans += u;
    return ans;
}

int main()
{
    Boost;
    cout << SNOD(120);
    return 0;
}
