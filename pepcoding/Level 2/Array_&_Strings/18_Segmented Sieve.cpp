// 1. Generate all primes between 'a'  and 'b'(both are included).
// 2. Print every number in new line.
// 3. Allowed time Complexity : O(nlog(log n)), where n = b - a.
// 4. Allowed Space Complexity : O(n), where n = b -a;
// Note : Please focus on constraints.

#include "../header.h"

vi sieve(int n)
{
    vi isPrime(n + 1, 1), prime;

    for (int i = 2; i * i <= isPrime.size(); i++)
        for (int j = i * i; j < isPrime.size(); j += i)
            isPrime[j] = false;

    for (int i = 2; i <= isPrime.size(); i++)
        if (isPrime[i] == true)
            prime.pb(i);

    return prime;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int b_sqrt = sqrt(b);
    vi primes = sieve(b_sqrt);

    vi arr(b - a, 1);

    for (int prime : primes)
    {
        int multiple = ceil(a * 1.0 / prime);
        if (multiple == 1)
            multiple++;

        int idx = multiple * prime - a;
        for (int j = idx; j < arr.size(); j += prime)
            arr[j] = false;
    }

    vi ans;

    for (int i = 0; i < arr.size(); i++)
        if (arr[i])
            // cout << a + i << " ";
            ans.pb(a + i);
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
22 51
*/
