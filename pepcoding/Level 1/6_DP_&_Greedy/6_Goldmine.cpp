// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
// 4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from
//      any row in the left wall.
// 5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug out from the mine.

#include "../header.h"

int maxgold(int gold[N][M], int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i > n || j > m)
        return 0;
    if (j == m)
        return gold[i][j];
    return gold[i][j] + max(maxgold(gold, i - 1, j + 1, n, m),
                            max(maxgold(gold, i, j + 1, n, m), maxgold(gold, i + 1, j + 1, n, m)));
}

int main()
{
    cout << "hello!" << endl;

    int n, m;
    cin >> n >> m;
    int arr[N][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    int dp[N][N] = {0};

    cout << endl;

    for (int k = 0; k < n; k++)
        cout << maxgold(arr, k, 0, n, m) << " ";

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
2 7 0 8 5 1
*/