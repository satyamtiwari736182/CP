// 1. Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
// 2. Write an algorithm to minimize the largest sum among these m subarrays.

#include "../header.h"
bool check(vi &arr, int value, int m)
{
    int cnt_grp = 1, temp_val = 0;
    for (int val : arr)
    {
        temp_val += val;
        if (temp_val > value)
        {
            temp_val = val;
            cnt_grp++;
        }
    }

    return cnt_grp <= m;
}

int solve(vi &arr, int m)
{
    int low = 0, high = 0, value = 0;
    for (int i : arr)
    {
        low = max(low, i);
        high += i;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid, m) == 1)
        {
            value = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return value;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> m;

        cout << "\n============================================\n";

        cout << solve(arr, m);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 4
// 12 30 48 10
// 2

// 5
// 7 2 5 10 8
// 2