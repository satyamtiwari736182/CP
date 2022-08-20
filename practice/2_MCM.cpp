#include "header.h"
bool isPalindrome(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}
int solver(string str, int i, int j, vvi &dp)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    if (isPalindrome(str, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    for (int k = i; k < j; k++)
    {
        int tempAns = 1;
        // int tempAns = 1 + solver(str, i, k, dp) + solver(str, k + 1, j, dp);
        //-------------------------------
        if (dp[i][k] != -1)
            tempAns += dp[i][k];
        else
            tempAns += solver(str, i, k, dp);

        if (dp[k + 1][j] != -1)
            tempAns += dp[k + 1][j];
        else
            tempAns += solver(str, k + 1, j, dp);
        //-------------------------------
        ans = min(ans, tempAns);
    }
    return dp[i][j] = ans;
}
void solve()
{
    string str = "pepcodingni";
    int n = str.size();
    // cin >> n;
    int *arr = new int[n];
    // rarr(arr, 0, n);
    vvi dp(n, vi(n, -1));
    cout << solver(str, 0, n - 1, dp) << "\n*******\n";
    // cout << setw(10);
    pmatrix(dp, n, n);
}

int main()
{
    cout << "hello\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// #include "header.h"
// int solver(int *arr, int i, int j, vvi &dp)
// {
//     int ans = INT_MAX;
//     if (i >= j)
//         return 0;
//     if (dp[i][j])
//         return dp[i][j];
//     for (int k = i; k < j; k++)
//     {
//         int tempAns = solver(arr, i, k, dp) + solver(arr, k + 1, j, dp);
//         ans = min(ans, tempAns + arr[i - 1] * arr[k] * arr[j]);
//     }
//     return dp[i][j] = ans;
// }
// void solve()
// {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     rarr(arr, 0, n);
//     vvi dp(n, vi(n));
//     cout << solver(arr, 1, n - 1, dp) << "\n*******\n";
//     // cout << setw(10);
//     pmatrix(dp, n, n);
// }

// int main()
// {
//     cout << "hello\n";
//     int t = 1;
//     // cin>>t;
//     test(t)
//         solve();
//     return 0;
// }