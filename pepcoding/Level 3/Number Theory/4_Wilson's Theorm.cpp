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
        int n, p;
        cin >> n >> p;

        if (n >= p)
        {
            cout << "0" << endl;
            return 0;
        }

        ll ans = p - 1;
        for (int i = n + 1; i < p; i++)
            ans = (ans * pow(i, p - 2, p)) % p;
            
        cout << ans << endl;

    }

    return 0;
}