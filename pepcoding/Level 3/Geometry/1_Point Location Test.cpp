// https://cses.fi/problemset/task/2189

// with respect to line

#include "../header.h"

string solve()
{
    Point p1, p2, p3;
    p1 = getCoordinates(), p2 = getCoordinates(); // line
    p3 = getCoordinates();                        // point

    lld slope1 = (p2.y - p1.y) * (p3.x - p2.x);
    lld slope2 = (p3.y - p2.y) * (p2.x - p1.x);
    cout << (slope1) << " " << (slope2) << endl;
    lld diff = slope1 - slope2;

    if (diff > 0)
        return "RIGHT";
    else if (diff == 0)
        return "TOUCH";
    else
        return "LEFT";
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        cout << solve();

        cout << "\n------------------------------\n";
    }

    return 0;
}

// 3
// 1 1 5 3 2 3
// 1 1 5 3 4 1
// 1 1 5 3 3 2

// 3
// 1 1 5 3 2 3
// 1 1 5 3 4 1
// 1 1 5 3 3 2