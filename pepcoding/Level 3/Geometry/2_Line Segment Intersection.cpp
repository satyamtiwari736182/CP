
#include "../header.h"

string solve()
{
    Point p1, p2, p3, p4;
    p1 = getCoordinates(), p2 = getCoordinates(); // Line 1
    p3 = getCoordinates(), p4 = getCoordinates(); // Line 2

    lld pos_p3_line1 = orentation(p1, p2, p3);
    lld pos_p4_line1 = orentation(p1, p2, p4);

    lld pos_p1_line2 = orentation(p3, p4, p1);
    lld pos_p2_line2 = orentation(p3, p4, p2);

    if (pos_p1_line2 != pos_p2_line2 && pos_p3_line1 != pos_p4_line1)
        return "YES";

    else if (pos_p1_line2 == 0 && onSeg(p1, p2, p3))
        return "YES";
    else if (pos_p2_line2 == 0 && onSeg(p1, p2, p4))
        return "YES";
    else if (pos_p3_line1 == 0 && onSeg(p3, p4, p1))
        return "YES";
    else if (pos_p4_line1 == 0 && onSeg(p3, p4, p2))
        return "YES";

    return "NO";
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

// 5
// 1 1 5 3 1 2 4 3
// 1 1 5 3 1 1 4 3
// 1 1 5 3 2 3 4 1
// 1 1 5 3 2 4 4 1
// 1 1 5 3 3 2 7 4