// Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points symmetrically, in other words, answer whether or not if there exists a line that after reflecting all points over the given line the set of the original points is the same that the reflected ones.

// Note that there can be repeated points.

// Example 1:
// Input: points = [[1,1],[-1,1]]
// Output: true
// Explanation: We can choose the line x = 0.

// Example 2:
// Input: points = [[1,1],[-1,-1]]
// Output: false
// Explanation: We can't choose a line.

#include "../header.h"

bool isReflected(vvi &points)
{
    unordered_map<ll, ll> hashmap;
    int xmin = INT_MAX, xmax = INT_MIN;
    for (auto pt : points)
    {
        int x = pt[0], y = pt[1];
        xmin = min(xmin, x), xmax = max(xmax, x);
        ll hash = x * 10000000 + y;
        hashmap[hash] = 1;
    }

    ll mirr = xmin + xmax;

    for (auto pt : points)
    {
        int x = pt[0], y = pt[1];
        ll ximg = mirr - x, yimg = y;
        ll imghash = ximg * 10000000 + y;
        if (hashmap.count(imghash) == false)
            return false;
    }

    return true;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vvi points(n, vi(2));
        rmatrix(points, n, 2);

        cout << "\n============================================\n";
        cout << isReflected(points);
        cout << "\n============================================\n";
    }

    return 0;
}

/*
3
1 1
9 1
8 2
*/