// https://leetcode.com/problems/battleships-in-a-board/

#include "../header.h"

int cntBattleShips(vector<vector<char>> &grid)
{
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 'X')
            {
                if (i == 0 && j == 0)
                    cnt++;
                else if (i == 0 && grid[i][j - 1] != 'X')
                    cnt++;
                else if (j == 0 && grid[i - 1][j] != 'X')
                    cnt++;
                else if (grid[i][j - 1] != 'X' && grid[i - 1][j] != 'X')
                    cnt++;
            }
    return cnt;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    rmatrix(arr, n, m);
    cout << "--------------------" << endl;
    cout << cntBattleShips(arr);
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
X X X
. . .
X . X
X . X
*/
