// 1. A group of two or more people wants to meet and minimize the total travel distance.
// 2. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
// 3. Return min distance where distance is calculated using 'Manhattan Distance', where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

#include "../header.h"

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    Fill(arr, 0);
    rmatrix(arr, n, m);
    cout << "\n===========\n";

    vi xcordi, ycordi;
    // 1. Get sorted x-getCoordinates
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            if (arr[r][c])
                xcordi.pb(r);

    // 2. Get sorted y-getCoordinates
    for (int c = 0; c < m; c++)
        for (int r = 0; r < n; r++)
            if (arr[r][c])
                ycordi.pb(c);

    // 3.calculate median cordinates.
    int x = xcordi[xcordi.size() / 2];
    int y = ycordi[ycordi.size() / 2];

    // 4.calulate manhatten distance.
    int dist = 0;
    for (int xi : xcordi)
        dist += abs(x - xi);
    for (int yi : ycordi)
        dist += abs(y - yi);
    //   pmatrix(arr, n, m);
    cout << dist << endl;
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

3 5
1 0 0 0 1
0 0 0 0 0
0 0 1 0 0

*/
