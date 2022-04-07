// 1. You are given a number x.
// 2. You are given another number n.
// 3. You are required to calculate x raised to the power n mod 10^9 + 7 in logn complexity.

#include "../header.h"

int pow(ll x, ll n, ll p)
// Modular Fast Exponentiation/(Binary Exponentiation)
{
    ll ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = (ans * x) % p;
            n--;
        }
        x = (x * x) % p;
        n /= 2;
    }
    return (int)ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    test(t)
    {
        int x, n;
        cin >> x >> n;
        int ans = pow(x, n, mod);
        cout << ans << endl;
    }

    return 0;
}

// 1
// 10 5