#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007

#define Boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void normal(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
}
ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a * b) % mod;
}
ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a + b) % mod;
}
ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
ll modPow(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = modMul(r, b);
        }
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
ll modInverse(ll a)
{
    return modPow(a, mod - 2);
}
ll modDiv(ll a, ll b)
{
    return modMul(a, modInverse(b));
}

int main()
{
    Boost;
    ll n;
    cin >> n;
    cout << modPow(2, n) << endl;
    return 0;
}
