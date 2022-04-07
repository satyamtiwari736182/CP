
#include "../header.h"

ll solve()
{
    vector<Point> polygon, pts;
    vs ans;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        polygon.pb(getCoordinates());
    for (int i = 0; i < m; i++)
        pts.pb(getCoordinates());

    Point infinity(INT_MAX, INT_MAX - 1);
    for (auto pt : pts)
    {
        int intersec_cnt = 0;
        bool onBoundry = false;
        for (int i = 0; i < n; i++)
        {
            Point A = polygon[i], B = polygon[(i + 1) % n];
            if (orentation(A, B, pt) == 0 && onSeg(A, B, pt))
            {
                onBoundry = true;
                break;
            }
            if (intersects(pt, infinity, A, B))
                intersec_cnt++;
        }
        if (onBoundry)
            ans.pb("BOUNDARY");
        else if (intersec_cnt % 2 == 1)
            ans.pb("INSIDE");
        else
            ans.pb("OUTSIDE");
    }
    for (auto res : ans)
        cout << res << " ";
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();

        cout << "\n------------------------------\n";
    }

    return 0;
}
