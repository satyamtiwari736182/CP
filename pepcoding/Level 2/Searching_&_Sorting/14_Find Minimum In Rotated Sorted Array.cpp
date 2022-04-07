// 1. Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
// 2. Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// 3. Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// 4. You must write an algorithm that runs in O(log n) time.

#include "../header.h"
int solve(vi &arr)
{
    int min_ele = -1;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid + 1] < arr[mid])
            return arr[mid + 1];
        else if (arr[mid - 1] > arr[mid])
            return arr[mid];
        else if (arr[low] <= arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return min_ele;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";

        cout << solve(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 3

// 6
// 5 6 1 2 3 4

// 8
// 4 5 6 7 8 -5 1 3

// 7
// 4 5 6 7 0 1 2