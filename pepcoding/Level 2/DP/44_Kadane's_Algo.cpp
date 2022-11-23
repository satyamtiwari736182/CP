/*
1. You are given an array(arr) of integers.
2. You have to find maximum subarray sum in the given array.
3. The subarray must have at least one element.
*/

#include "../header.h"

int main()
{
    int n;
    cin >> n;
    int arr[N];
    arr[0] = 0;
    rarr(arr, 1, n + 1);
    int dp[N] = {0}, mx = INT_MIN;

    //-----------------------------------------------------
    // Kadane's Algorithm for max sum subarray
    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] + arr[i] > arr[i])
            dp[i] = dp[i - 1] + arr[i];
        else
            dp[i] = arr[i];
    }
    //-----------------------------------------------------
    cout << "\nHello world!\n";
    parr(dp, n + 1);
    return 0;
}

// 18
// 4 3 -2 6 -14 7 -1 4 5 7 -10 2 9 -10 -5 -9 6 1
