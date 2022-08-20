// 1. Given a sorted array containing only 0s and 1s, find the transition point.
// 2. Transition Point is defined as 1's starting point.
// 3. If there is no transition point, return -1.

#include "../header.h"

void solve(vi &arr)
{
    int i = -1, j = -1, target = 1;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            i = mid;
            high = mid - 1;
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << i << endl;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";
        solve(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
6
0 0 0 0 1 1
*/