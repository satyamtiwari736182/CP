// 1. You have a matrix of N*N Dimension.
// 2. You have to convert matrix into transpose.
// 3. Transpose matrix is defined as, matrix flipped over its main diagonal.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;

    int arr[100][100], transpose[100][100];
    // Fill(arr, 0), Fill(transpose, 0);
    rmatrix(arr, n, n);
    cout << "\n------------\n";

    for (int row = 0; row < n; row++)
        for (int col = 0; col <= row; col++)
            swap(arr[col][row], arr[row][col]);

    pmatrix(arr, n, n);
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
3
11 12 13
21 22 23
31 32 33
*/
