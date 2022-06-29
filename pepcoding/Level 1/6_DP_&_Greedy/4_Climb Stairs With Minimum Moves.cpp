// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you
//      could jump to in a single move.  You can of-course fewer number of steps in the move.
// 4. You are required to print the number of minimum moves in which you can reach the top of
//      staircase.
// Note -> If there is no path through the staircase print null.

#include "../header.h"

int getstairminV_U_R(int n, int *arr, int idx)
{
    if (idx >= n)
        return 0;
    int mini = INT_MAX;
    if (arr[idx] == 0)
        return -1;
    for (int i = 1; i <= arr[idx]; i++)
    {
        int g = getstairminV_U_R(n, arr, i + idx);
        if (g != -1)
            mini = min(mini, g);
    }
    return mini + 1;
}

int getstairminV_U_T(int n, int *arr, int *dp)
{
    dp[n] = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        int mini = INT_MAX;
        if (arr[i] == 0)
        {
            dp[i] = -1;
            continue;
        }
        for (int j = 1; j <= arr[i]; j++)
            if (dp[i + j] != -1)
                mini = min(mini, dp[i + j]);

        dp[i] = mini + 1;
    }
    return dp[1];
}

int getstairminV_U_M(int n, int *arr, int idx, int *dp)
{
    int mini = INT_MAX;
    if (idx > n)
    {
        dp[idx] = mini;
        return mini;
    }
    if (idx == n)
    {
        dp[idx] = 1;
        return 1;
    }
    if (dp[idx])
        return dp[idx];
    for (int i = 1; i <= arr[idx]; i++)
    {
        if ((i + idx) <= n && dp[i + idx])
            return dp[i + idx];
        mini = min(mini, getstairminV_U_M(n, arr, i + idx, dp));
    }
    dp[idx] = mini + 1;
    return dp[idx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << "hello!" << endl;
    int path = 0, n;
    cin >> n;
    int arr2[100] = {0}, arr[100] = {0}; // n+1

    for (int i = 1; i <= n; i++)
        cin >> arr2[i];

    cout << getstairminV_U_T(n, arr2, arr) << endl;
    parr(arr, n + 1);

    return 0;
}

/*
10
3 2 4 2 0 2 3 1 2 2
*/

// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0