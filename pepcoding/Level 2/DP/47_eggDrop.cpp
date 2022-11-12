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