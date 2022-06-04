// 1. Given an Integer 'n'.
// 2. Print all primes from 2 to 'n'.
// 3. Portal is not forced you, but try to submit the problem in less than n.root(n) complexity.


#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi isPrime(n + 1, 1);

    for (int i = 2; i * i <= isPrime.size(); i++)
        for (int j = i * i; j < isPrime.size(); j += i)
            isPrime[j] = false;

    for (int i = 2; i <= isPrime.size(); i++)
        if (isPrime[i])
            cout << i << " ";
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*
50
*/
