// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
// 4. You are standing in the top-left corner and have to reach the bottom-right corner.
// Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
// 5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

// Note1 -> Please check the sample input and output for details
// Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'

#include "../header.h"

void floodfill(int arr[N][M], int visited[N][M], int i, int j, int n, int m, string ans)
{

    if (i < 0 || j < 0 || i == n || j == m || arr[i][j] == 1 || visited[i][j] == 1)
        return;

    if (i == n - 1 && j == m - 1)
    {
        cout << ans << " ";
        return;
    }
    visited[i][j] = 1;

    floodfill(arr, visited, i, j + 1, n, m, "r" + ans);
    floodfill(arr, visited, i, j - 1, n, m, "l" + ans);
    floodfill(arr, visited, i - 1, j, n, m, "u" + ans);
    floodfill(arr, visited, i + 1, j, n, m, "d" + ans);

    visited[i][j] = 0;
}

void solve()
{
    int arr[N][M], visited[N][M];
    int n, m;
    cin >> n >> m;
    rmatrix(arr, n, m);
    cout << "\n************\n";
    // pmatrix(arr, n, m);
    memset(visited, 0, sizeof(visited));
    floodfill(arr, visited, 0, 0, n, m, "");
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// 3 3
// 0 0 0
// 1 0 1
// 0 0 0