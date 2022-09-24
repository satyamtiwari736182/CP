// You are given an m * n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



#include "../header.h"

int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vi> &grid, int row, int col)
{
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
        return;

    grid[row][col] = 0;
    for (int i = 0; i < 4; i++)
    {
        int rowdash = row + dirs[i][0];
        int coldash = col + dirs[i][1];
        dfs(grid, rowdash, coldash);
    }
}

int num_of_enclave(vector<vi> &grid)
{
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] && i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
                dfs(grid, i, j);

    int count = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j])
                count++;

    return count;
}
int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    cout << num_of_enclave(grid) << endl;
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 0 0 0 1 0
// 0 1 1 0 0
// 0 1 0 1 1
// 0 0 1 1 0
// 0 1 1 0 0