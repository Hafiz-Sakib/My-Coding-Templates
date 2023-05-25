#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define Boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// SNOD in O(n) Complexity

ll SNOD(ll n)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (n / i);
    }
    return sum;
}

int main()
{
    Boost;
    cout << SNOD(120);
    return 0;
}
