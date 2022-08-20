#include "../header.h"

int main()
{
    int n, i = 0;
    cin >> n;
    // int arr[n], dp[n][n];
    int arr[N], dp[N][N];
    REP(i, 0, n - 1)
    cin >> arr[i];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            if (g == 0)
                dp[i][j] = arr[i];
            else if (g == 1)
                dp[i][j] = max(arr[i], arr[j]);
            else
            {
                int val1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                int score = max(val1, val2);
                dp[i][j] = score;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < i; k++)
            cout << "   ";
        for (int j = i; j < n; j++)
        {
            string str = "0" + to_string(dp[i][j]);
            if (dp[i][j] <= 9)
                cout << str << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nhello!  " << dp[0][n - 1] << endl;
    return 0;
}

// 4
// 20 30 2 10