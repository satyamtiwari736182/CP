/*
1. You are given two integers N and K. N represents the number of eggs and K represents the number of floors in a building.
2. You have to find the minimum number of attempts you need in order to find the critical floor in the worst case while using the best strategy.
3. The critical floor is defined as the lowest floor from which you drop an egg and it doesn't break.
4. There are certain which you have to follow -
   a. All eggs are identical.
   b. An egg that survives a fall can be used again.
   c. A broken egg can't be used again.
   d. If the egg doesn't break at a certain floor, it will not break at any floor below.
   e. If the egg breaks at a certain floor, it will break at any floor above.
*/

#include "../header.h"
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    // int dp[n + 1][k + 1];
    int dp[N][N];
    memset(dp, 0, sizeof(dp));

    //---------------------------------------------
    for (int e = 0; e <= n; e++)
    {
        for (int f = 0; f <= k; f++)
        {
            if (f == 0)
                dp[e][f] = 0;
            else if (f == 1)
                dp[e][f] = 1;
            else if (e == 0)
                dp[e][f] = -1;
            else if (e == 1)
                dp[e][f] = f;
            else
            {
                int minAttempt = INT_MAX;
                for (int r = 1; r < f; r++) // r th => floor
                {
                    int val = max(dp[e][f - r], dp[e - 1][r - 1]);
                    minAttempt = min(val, minAttempt);
                }
                dp[e][f] = minAttempt + 1;
            }
        }
    }
    //---------------------------------------------

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << "\nHello!\n"
         << dp[n][k]
         << endl;
    return 0;
}