// 1. Given an integer array 'arr',
// 2. Find three numbers whose product is maximum and return the maximum product.

#include "../header.h"

void solve()
{
    int n, min1 = INF, min2 = INF, max1 = -INF, max2 = -INF, max3 = -INF;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    for (int val : arr)
    {
        // finding 3 maximum element
        if (val >= max1)
            max3 = max2, max2 = max1, max1 = val;
        else if (val >= max2)
            max3 = max2, max2 = val;
        else
            max3 = val;

        // finding 2 minimum element
        if (val <= min1)
            min2 = min1, min1 = val;
        else if (val <= min2)
            min2 = val;
    }

    int pro = max(max1 * max2 * max3, max1 * min1 * min2);
    cout << pro << endl;
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*

6
3 2 -4 -6 5 1

*/
