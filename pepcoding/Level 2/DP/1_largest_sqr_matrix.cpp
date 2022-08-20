#include "../header.h"
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100], dp[100][100];

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 || j == m - 1 || arr[i][j] == 0)
                dp[i][j] = arr[i][j];
            else
            {
                dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j]));
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
            // else
            //     dp[i][j] = arr[i][j];
        }
    cout << "\n*******************\n"
         << endl;
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}

// 5 6
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 1 1 1 0
// 0 0 1 1 1 0
// 1 1 1 1 1 1