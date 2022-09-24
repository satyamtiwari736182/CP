// You are given an m * n matrix containing 0, 1 or 2 , where 0 represents an empty cell, 1 represents a fresh orange, 2 represents rotten orange. Every hour, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Print the minimum number of hours that must elapse until no cell has a fresh orange.

// In case if all the oranges can't become rotten print -1

#include "../header.h"

class Pair1
{
public:
    int x, y;
    Pair1(int x1, int y1) : x(x1), y(y1) {}
};

void time_rott_oranges(vector<vi> &grid)
{
    int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<Pair1 *> que;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 2)
                que.push(new Pair1(i, j));

    int time = 0;
    while (!que.empty())
    {
        int size = que.size();
        time++;
        while (size--)
        {
            Pair1 *rem = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int rowdash = rem->x + dirs[i][0];
                int coldash = rem->y + dirs[i][1];

                if (rowdash >= 0 && coldash >= 0 && rowdash < grid.size() && coldash < grid[0].size() && grid[rowdash][coldash] == 1)
                {
                    grid[rowdash][coldash] = -time; // time is denoted as ve- to avoid collision with fresh and rotton oranges.
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
    time_rott_oranges(grid);
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 2 0 1 0 1
// 1 1 1 0 0
// 0 0 0 0 0
// 0 0 1 1 1
// 0 1 1 2 0

// 0 -> empty space.
// 1 -> fresh oranges.
// 2 -> rotton oranges.