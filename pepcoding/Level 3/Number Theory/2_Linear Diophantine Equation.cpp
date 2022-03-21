#include "../header.h"

class Pair
{
public:
    Pair(ll xx, ll yx, ll gcdx) : x(xx), y(yx), gcd(gcdx) {}
    ll x, y, gcd;
};

Pair euclide(int a, int b)
{
    if (b == 0)
        return Pair(1, 0, a);
    Pair dash = euclide(b, a % b);
    return Pair(dash.y, dash.x - (a / b) * dash.y, dash.gcd);
}

int main()
{
    cout << "\nHello world!" << endl;
    int a, b, k, t;
    cin >> t;
    test(t)
    {
        cin >> a >> b >> k;
        Pair ans = euclide(a, b);
        ans.x *= k;
        ans.y *= k;
        cout << ans.x << "\t" << ans.y << endl;
    }

    return 0;
}