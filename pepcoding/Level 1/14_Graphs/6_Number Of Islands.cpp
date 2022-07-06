// 1. You are given a 2d array where 0's represent land and 1's represent water.
//      Assume every cell is linked to it's north, east, west and south cell.
// 2. You are required to find and count the number of islands.

#include "../header.h"

void markIsland(int grph[M][N], int n, int m, int sr, int sc, bool visited[M][N])
{

    if (sr >= n || sc >= m || sr < 0 || sc < 0 || grph[sr][sc] == 1 || visited[sr][sc] == true)
        return;
    visited[sr][sc] = true;

    markIsland(grph, n, m, sr, sc + 1, visited);
    markIsland(grph, n, m, sr, sc - 1, visited);
    markIsland(grph, n, m, sr + 1, sc, visited);
    markIsland(grph, n, m, sr - 1, sc, visited);
}

int noIsland(int grph[M][N], int n, int m)
{
    int count = 0;
    bool visited[M][N];
    memset(visited, 0, sizeof(visited));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grph[row][col] == 0 && visited[row][col] == false)
            {
                count++;
                markIsland(grph, n, m, row, col, visited);
            }
        }
    }

    return count;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[M][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << endl;
    cout << noIsland(arr, n, m) << endl;
}

int main()
{
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
8
8
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 0 0 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
*/