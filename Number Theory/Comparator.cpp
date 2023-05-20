#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    // first smaller,second greater
    if (a.first < b.first)
    {
        return 1;
    }
    else if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return 0;
}

int main()
{
    return 0;
}
