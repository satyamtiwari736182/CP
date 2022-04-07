// https://cses.fi/problemset/task/2191

#include "../header.h"

ll solve()
{
    vector<Point> pts;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        pts.pb(getCoordinates());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        Point A = pts[i], B = pts[(i + 1) % n];
        ans += A.x * B.y - A.y * B.x;
    }
    return abs(ans);
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        cout << solve();

        cout << "\n------------------------------\n";
    }

    return 0;
}

// 4
// 1 1
// 4 2
// 3 5
// 1 4