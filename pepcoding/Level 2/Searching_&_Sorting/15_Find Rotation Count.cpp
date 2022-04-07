// 1. Given an ascending sorted rotated array arr of distinct integers of size N.
// 2. The array is right rotated K times.
// 3. Your task is to find the value of K.

#include "../header.h"
int solve(vi &arr)
{
    int rotation_cnt = -1;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid + 1] < arr[mid])
            return (mid + 1);
        else if (arr[mid - 1] > arr[mid])
            return mid;
        else if (arr[low] <= arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return rotation_cnt;
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