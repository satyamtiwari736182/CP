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
        int tempAns = 1 + solver(str, i, k, dp) + solver(str, k + 1, j, dp);
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