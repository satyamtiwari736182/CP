// 1. Given n non-negative integers a1, a2, ..., an.
// 2. Each represents a point at coordinate (i, ai).
// 3. 'n' vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
// 4. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
// 5. (Not volume because we are working with 2D so amount of water is basically Area).
// Note : that you may not slant the container.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);

    int i = 0, j = n - 1, maxWater = 0;
    while (i < j)
    {
        int width = j - i;
        maxWater = max(maxWater, width * min(arr[i], arr[j]));
        if (arr[i] > arr[j])
            j--;
        else
            i++;
    }
    cout << maxWater << endl;
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
9
1 8 6 2 5 4 8 3 7
*/