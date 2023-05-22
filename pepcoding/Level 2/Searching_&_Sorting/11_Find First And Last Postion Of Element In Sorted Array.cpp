// 1. Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
// 2. If target is not found in the array, return [-1, -1].
// 3. You must write an algorithm with O(log n) runtime complexity.

#include "../header.h"
pi solve(vi &arr, int target)
{
    //***************************************************
    int s = lower_bound(all(arr), target) - begin(arr);     //? It return first occuring position of the target if present else it behave like upper_bound().
    int e = upper_bound(all(arr), target) - begin(arr) - 1; //? It return value just grater than target.
    cout << s << " " << e << endl;
    //***************************************************
    int i = -1, j = -1, flag = 0;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            flag = 1;
            i = mid;
            high = mid - 1;
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            flag = 1;
            j = mid;
            low = mid + 1;
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    // if (flag == 0)
    //     return {-1, -1};

    return {i, j};
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, tar;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> tar;

        cout << "\n============================================\n";

        pi ans = solve(arr, tar);
        cout << ans.fs << " " << ans.se;

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 7
// 2 2 3 3 3 4 5
// 3

// 9
// 1 1 2 2 2 2 2 4 5
// 2