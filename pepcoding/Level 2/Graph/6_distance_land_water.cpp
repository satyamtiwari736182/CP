// Given an n*n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

#include "../header.h"

class Pair1
{
public:
    int x, y;
    Pair1(int x1, int y1) : x(x1), y(y1) {}
};

void nearest_one_from_zero(vector<vi> &grid)
{
    int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<Pair1 *> que;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 1)
                que.push(new Pair1(i, j));

    int distance = 0;
    while (!que.empty())
    {
        int size = que.size();
        distance++;
        while (size--)
        {
            Pair1 *rem = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int rowdash = rem->x + dirs[i][0];
                int coldash = rem->y + dirs[i][1];

                if (rowdash >= 0 && coldash >= 0 && rowdash < grid.size() && coldash < grid[0].size() && grid[rowdash][coldash] == 0)
                {
                    grid[rowdash][coldash] = distance;
                    que.push(new Pair1(rowdash, coldash));
                }
            }
        }
    }
}

int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    nearest_one_from_zero(grid);
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 1 0 0 0 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 0 0 0 1
