#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e8;

vector<int> Divisors;

void Divisor(int n)
{
    Divisors.clear();

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            Divisors.push_back(i);
            if (n / i != i)
            {
                Divisors.push_back(n / i);
            }
        }
    }

    sort(Divisors.begin(), Divisors.end());

    for (auto u : Divisors)
    {
        cout << u << ' ';
    }
    cout << endl;
}

int main()
{
    return 0;
}
