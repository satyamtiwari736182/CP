// 1. You will be given a matrix, 2d Array and number of its columns and rows.
//  2. Matrix represents a grid, where 1 is land and 0 is water.
//  3. Each tile/element has 1 as width and height.
//  4. You need to find perimeter of the island formed by land.
//  5. Input and output is handled for you
//  6. It is a functional problem, please do not modify main()

#include "../header.h"

int landPerimeter(vvi &grid)
{
    int perimeter = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == true)
            {
                perimeter += 4;
                if (j > 0 && grid[i][j - 1] == 1)
                    perimeter -= 2;
                if (i > 0 && grid[i - 1][j] == 1)
                    perimeter -= 2;
            }
    return perimeter;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    rmatrix(arr, n, m);
    cout << "--------------------" << endl;
    cout << landPerimeter(arr);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*
4 3
1 0 0
1 1 1
0 1 0
0 1 0
*/
