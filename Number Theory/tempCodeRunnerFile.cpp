    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto u : PrimeFactors[i])
        {
            cout << u << ' ';
        }
        cout << endl;
    }