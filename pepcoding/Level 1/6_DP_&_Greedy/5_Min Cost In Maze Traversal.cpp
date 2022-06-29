// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.

#include "../header.h"

int mincost(int arr[][M], int n, int m, int dp[][M])
{
    if (n < 0 || m < 0)
        return INT_MAX;
    if (n == 0 && m == 0)
        return arr[n][m];
    if (dp[n][m] != 0)
        return dp[n][m];
    dp[n][m] = arr[n][m] + min(mincost(arr, n - 1, m, dp), mincost(arr, n, m - 1, dp));
    return dp[n][m];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    cout << "hello!" << endl;
    // Minimum cost while travelling from left to right corner with right and down move.
    int n, m;
    cin >> n >> m;
    int arr[N][N];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    int dp[N][N] = {0};

    for (int r = n; r > 0; r--)
    {
        for (int c = m; c > 0; c--)
        {
            if (r == n && c == m)
                dp[r][c] = arr[r][c];
            else if (c == m)
                dp[r][c] = arr[r][c] + dp[r + 1][c];
            else if (r == n)
                dp[r][c] = arr[r][c] + dp[r][c + 1];
            else
                dp[r][c] = arr[r][c] + min(dp[r + 1][c], dp[r][c + 1]);
        }
    }

    cout << endl
         << dp[1][1] << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5
*/