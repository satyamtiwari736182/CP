//! 475591
// Given an m*n binary matrix mat, return the number of distinct island.

// An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.


#include "../header.h"

// int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
string psf;

void dfs(vector<vi> &grid, int row, int col)
{
    grid[row][col] = 0;
    if (col + 1 < grid[0].size() && grid[row][col + 1])
    {
        psf += "r";
        dfs(grid, row, col + 1);
    }
    if (col - 1 > 0 && grid[row][col - 1])
    {
        psf += "l";
        dfs(grid, row, col - 1);
    }
    if (row + 1 < grid.size() && grid[row + 1][col])
    {
        psf += "u";
        dfs(grid, row + 1, col);
    }
    if (row - 1 > 0 && grid[row - 1][col])
    {
        psf += "d";
        dfs(grid, row - 1, col);
    }
    psf += "z";
}

int num_of_distinct_island(vector<vi> &grid)
{
    int count = 0;
    set<string> hashset;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j])
            {
                psf = "x";
                dfs(grid, i, j);
                hashset.insert(psf);
            }
    count = hashset.size();
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
    cout << num_of_distinct_island(grid) << endl;
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 0 0 0 1 0
// 0 1 1 0 0
// 0 1 0 1 1
// 0 0 0 0 1
// 0 1 1 0 0