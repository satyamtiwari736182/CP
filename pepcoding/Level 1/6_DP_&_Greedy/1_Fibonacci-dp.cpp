// 1. You are given a number n.
// 2. You are required to print the nth element of fibonnaci sequence.

// Note -> Notice precisely how we have defined the fibonnaci sequence
// 0th element -> 0
// 1st element -> 1
// 2nd element -> 1
// 3rd element -> 2
// 4th element -> 3
// 5th element -> 5
// 6th element -> 8

#include "../header.h"

// Recursion
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// DP - Memoization
int fibm(int n, int *dp)
{
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return dp[n];
    }
    if (dp[n] != 0)
        return dp[n];
    dp[n] = fibm(n - 1, dp) + fibm(n - 2, dp);
    return dp[n];
}

// DP-Tabulation
void fibt(int n, int *dp)
{
    dp[0] = 0, dp[1] = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == 1)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> fibo;
    cout << "hello!" << endl;
    int arr[25] = {0};
    fibt(20, arr);
    parr(arr, 24);
    return 0;
}


// 10