// 1. You are given an n x n 2D matrix representing an image.
// 2. rotate the image by 90 degrees (clockwise).
// 3. You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// 4. DO NOT allocate another 2D matrix and do the rotation.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;

    int arr[100][100], transpose[100][100];

    rmatrix(arr, n, n);
    cout << "\n------------\n";

    // 1. Transpose
    for (int row = 0; row < n; row++)
        for (int col = 0; col <= row; col++)
            swap(arr[col][row], arr[row][col]);

    // 2. Reverse every row
    for (int row = 0; row < n; row++)
        reverse(arr[row], arr[row] + n);
        
    /* for (int row = 0; row < n; row++)
     {
         int row_ele[100];
         for (int i = 0; i < n; i++)
             row_ele[i] = arr[row][i];

         for (int i = n - 1, j = 0; i >= 0; i--, j++)
             arr[row][j] = row_ele[i];

     }*/

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

?
31 21 11
32 22 12
33 23 13

*/
