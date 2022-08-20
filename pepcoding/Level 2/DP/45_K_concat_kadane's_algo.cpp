#include "../header.h"

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    // arr[0] = 0;
    rarr(arr, 0, n);
    cin >> k;
    int *dp = new int[2 * n + 1], mx = INT_MIN;
    for (int i = 0; i <= 2 * n; i++)
        dp[i] = 0;

    int *arr2 = new int[2 * n + 1];
    arr2[0] = 0;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    for (int i = 0; i <= 2 * n; i++)
        arr2[i + 1] = arr[i % (n)];

    //-----------------------------------------------------
    // K concatinated Kadane's Algorithm for max sum subarray
    for (int i = 1; i <= 2 * n; i++)
    {
        if (dp[i - 1] + arr2[i] > arr2[i])
            dp[i] = dp[i - 1] + arr2[i];
        else
            dp[i] = arr2[i];
        if (mx < dp[i])
            mx = dp[i];
    }
    //-----------------------------------------------------
    // K concatinated Kadane's Algorithm
    int maxSubArrSum = 0;
    if (sum > 0)
        maxSubArrSum = mx + (k - 2) * sum;
    else
        maxSubArrSum = mx;
    //-----------------------------------------------------
    cout << "\nHello world! " << sum << "\n"
         << maxSubArrSum << endl;

    parr(arr2, 2 * n + 1);
    cout << endl;
    parr(dp, 2 * n + 1);
    return 0;
}

// 18
// 4 3 -2 6 -14 7 -1 4 5 7 -10 2 9 -10 -5 -9 6 1
// 4

// 5
// 3 -2 -3 1 2
// 4
