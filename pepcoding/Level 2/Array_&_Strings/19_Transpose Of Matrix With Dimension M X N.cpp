// 1. You have a matrix of M*N Dimension.
// 2. You have to return a Transpose matrix, where The transpose of a matrix is the matrix flipped over its main diagonal.


#include "../header.h"

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100], transpose[100][100];
    // Fill(arr, 0), Fill(transpose, 0);
    rmatrix(arr, n, m);
    cout << "\n------------\n";

    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
            transpose[col][row] = arr[row][col];

    pmatrix(transpose, m, n);
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
2 3
11 12 13
21 22 23
*/
