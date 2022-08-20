// Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice.

#include "../header.h"

int findSingleElement(vi &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        else if (arr[mid] == arr[mid - 1])
        {
            // low to mid inclusive  element counts.
            int left_cnt = mid - low + 1;
            if (left_cnt % 2 == 0)
                low = mid + 1;
            else
                high = mid - 2;
        }

        else if (arr[mid] == arr[mid + 1])
        {
            // high to mid inclusive element counts.
            int right_cnt = high - mid + 1;
            if (right_cnt % 2 == 0)
                high = mid - 1;
            else
                low = mid + 2;
        }
    }
    return -1;
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
        cout << findSingleElement(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
11
1 1 2 2 4 4 7 7 8 10 10
*/