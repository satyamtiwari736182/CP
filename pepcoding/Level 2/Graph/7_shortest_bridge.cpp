// Given an n*n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

#include "../header.h"

int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vvi &grid, int row, int col, vvi &vis, queue<pi> &que)
{
    vis[row][col] = true;
    que.push({row, col});
    for (int i = 0; i < 4; i++)
    {
        int rowdash = row + dirs[i][0];
        int coldash = col + dirs[i][1];
        if (rowdash < 0 || coldash < 0 || rowdash >= grid.size() || coldash >= grid[0].size() || grid[rowdash][coldash] == 0 || vis[rowdash][coldash] == true)
            continue;
        dfs(grid, rowdash, coldash, vis, que);
    }
}

int shortestBridge(vector<vi> &grid)
{
    vvi vis(grid.size(), vi(grid[0].size()));
    queue<pi> que;

    bool flag = 0;
    for (int i = 0; i < grid.size() && !flag; i++)
        for (int j = 0; j < grid[0].size() && !flag; j++)
            if (grid[i][j] == 1)
                flag = 1, dfs(grid, i, j, vis, que);

    int distance = 0, ans = INF;
    while (!que.empty())
    {
        int size = que.size();
        distance++;
        while (size--)
        {
            pi rem = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int rowdash = rem.fs + dirs[i][0];
                int coldash = rem.se + dirs[i][1];

                if (rowdash >= 0 && coldash >= 0 && rowdash < grid.size() && coldash < grid[0].size() && vis[rowdash][coldash] == 0)
                {
                    if (grid[rowdash][coldash] == 1)
                        return distance;
                    vis[rowdash][coldash] = true, que.push({rowdash, coldash});
                    // else
                    //     ans = min(ans, distance);
                }
            }
        }
    }
    return -1;
}

int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    cout << shortestBridge(grid) << endl;
    // pmatrix(grid, n, m);

    return 0;
}

/*
5 6
1 1 0 0 1 1
0 1 0 0 0 1
0 1 0 0 0 1
0 1 0 0 0 1
1 1 0 0 1 1
*/