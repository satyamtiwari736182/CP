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
                int minV = INT_MAX;
                for (int rf1 = f - 1, rf2 = 0; rf1 > 0; rf1--, rf2++) // rf1 => reverse floor
                {
                    int val = max(dp[e][rf1], dp[e - 1][rf2]);
                    minV = min(val, minV);
                }
                dp[e][f] = minV + 1;
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