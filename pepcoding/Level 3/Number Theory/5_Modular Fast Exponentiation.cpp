#include "../header.h"

int pow(ll x, ll n, ll p)
// Modular Fast Exponentiation
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