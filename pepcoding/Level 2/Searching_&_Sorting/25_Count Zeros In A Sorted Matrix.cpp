// Given a Binary Square Matrix where each row and column of the matrix is sorted in ascending order. Find the total number of Zeros present in the matrix.

#include "../header.h"

void solve(vvi &arr)
{
    int n = arr.size();
    int cnt = 0, row = 0, col = n - 1;
    while (row < n && col >= 0)
    {
        if (arr[row][col] == 1)
            col--;
        else
            cnt += col + 1, row++;
    }
    cout << endl
         << cnt << endl;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vvi arr(n, vi(n));
        rmatrix(arr, n, n);

        cout << "\n============================================\n";

        solve(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

/*
5
0 0 0 1 1
0 0 0 1 1
0 0 1 1 1
0 1 1 1 1
0 1 1 1 1
*/

// 2

// 3
// 0 0 1
// 0 1 1
// 0 1 1
