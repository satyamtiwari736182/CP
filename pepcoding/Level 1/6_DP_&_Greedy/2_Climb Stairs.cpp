// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. In one move, you are allowed to climb 1, 2 or 3 stairs.
// 4. You are required to print the number of different paths via which you can climb to the top.

#include "../header.h"

int getstairM(int n, int *dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
    {
        dp[n] = 1;
        return dp[n];
    }
    if (dp[n] != 0)
        return dp[n];
    dp[n] = getstairM(n - 1, dp) + getstairM(n - 2, dp) + getstairM(n - 3, dp);
    return dp[n];
}

int getStairT(int n, int *dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
            dp[i] = 1;
        else if (i <= 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[6] = {0};
    cout << "hello!" << endl;

    int s = getstairM(4, arr);
    parr(arr, 6);
    cout << endl
         << s;

    return 0;
}

// 4