// https://leetcode.com/problems/where-will-the-ball-fall/

#include "../header.h"

vi findBall(vvi &grid)
{
    int n = grid.size(), m = grid[0].size();
    vi res(m);
    for (int j = 0; j < m; j++)
    {
        int curr_pos = j, next_pos = -1;
        for (int i = 0; i < n; i++)
        {
            next_pos = curr_pos + grid[i][curr_pos];
            if (next_pos < 0 || next_pos >= m || grid[i][curr_pos] != grid[i][next_pos])
            {
                curr_pos = -1;
                break;
            }
            curr_pos = next_pos;
        }
        res[j] = curr_pos;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    rmatrix(arr, n, m);
    cout << "--------------------" << endl;
    vi res = findBall(arr);
    parr(res, res.size());
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
5 5
1 1 1 -1 -1
1 1 1 -1 -1
-1 -1 -1 1 1
1 1 1 1 -1
-1 -1 -1 -1 -1
*/
