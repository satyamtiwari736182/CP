// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

#include "../header.h"

int rainWaterTrapping_2(vvi &heights)
{
    int n = heights.size(), m = heights[0].size();
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pque;
    vvi visited(n, vi(m));
    // pushing boundary elements
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                pque.push({heights[i][j], {i, j}}), visited[i][j] = true;

    int dirs[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int water = 0;

    while (!pque.empty())
    {
        auto temp = pque.top();
        pque.pop();

        for (int i = 0; i < 4; i++)
        {
            int rowdash = temp.se.fs + dirs[i][0];
            int coldash = temp.se.se + dirs[i][1];

            if (rowdash >= 0 && rowdash < n && coldash >= 0 && coldash < m && visited[rowdash][coldash] == false)
            {
                water += max(0, temp.fs - heights[rowdash][coldash]);
                if (heights[rowdash][coldash] >= temp.fs)
                    pque.push({heights[rowdash][coldash], {rowdash, coldash}});
                else
                    pque.push({heights[temp.se.fs][temp.se.se], {rowdash, coldash}});
                visited[rowdash][coldash] = true;
            }
        }
    }
    return water;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    rmatrix(arr, n, m);
    cout << "\n------------\n";
    cout << rainWaterTrapping_2(arr) << endl;
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
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1
*/