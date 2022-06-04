// https://www.codechef.com/FEB19B/problems/MANRECT

#include "../header.h"

void solve()
{
    ll c1, c2, c3, c4, mid;

    cout << "Q " << 0 << " " << 0 << endl;
    cin >> c1;
    fflush(stdout);

    cout << "Q " << INF << " " << 0 << endl;
    cin >> c2;
    fflush(stdout);

    cout << "Q " << INF << " " << INF << endl;
    cin >> c3;
    fflush(stdout);

    mid = (c1 - c2 + INF) / 2;
    cout << "Q " << mid << " " << 0 << endl;
    cin >> c4;
    fflush(stdout);

    ll y1 = c4;
    ll x1 = c1 - y1;

    ll x2 = INF + y1 - c2;
    ll y2 = 2 * INF - x2 - c3;

    cout << "A " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    int i;
    cin >> i;
    fflush(stdout);
}


int main()
{
    // cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        solve();
    }

    return 0;
}