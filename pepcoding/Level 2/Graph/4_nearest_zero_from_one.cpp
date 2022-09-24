// Given an m*n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

#include "../header.h"

class Pair1
{
public:
    int x, y;
    Pair1(int x1, int y1) : x(x1), y(y1) {}
};

void nearest_zero_from_one(vector<vi> &grid)
{
    int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<Pair1 *> que;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
                que.push(new Pair1(i, j));
            else
                grid[i][j] = -1;
        }

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

                if (rowdash >= 0 && coldash >= 0 && rowdash < grid.size() && coldash < grid[0].size() && grid[rowdash][coldash] == -1)
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
    nearest_zero_from_one(grid);
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 0 1 1 1 0
// 1 1 1 1 0
// 0 1 1 1 1
// 1 0 1 1 1
// 1 1 1 1 1