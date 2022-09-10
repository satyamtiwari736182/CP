// https://leetcode.com/problems/sort-the-matrix-diagonally/

#include "../header.h"

void countSort(vvi &arr, int row, int col)
{
    int n = arr.size(), m = arr[0].size();
    int i = row, j = col;
    int cnt[101] = {0};
    while (i < n && j < m)
        cnt[arr[i++][j++]]++;

    i = row, j = col;

    for (int k = 1; k < 101; k++)
        while (cnt[k] > 0)
            arr[i++][j++] = k, cnt[k]--;
}

void diagnolSort(vvi &arr)
{
    int n = arr.size(), m = arr[0].size();
    for (int i = 0; i < n; i++)
        countSort(arr, 0, i);

    for (int j = 1; j < m; j++)
        countSort(arr, j, 0);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    rmatrix(arr, n, m);
    cout << "--------------------" << endl;
    diagnolSort(arr);
    pmatrix(arr, n, m);
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
3 4
3 3 1 1
2 2 1 2
1 1 1 2
*/
