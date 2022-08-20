// Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

#include "../header.h"

int binarySearch(vvi &arr, int row)
{
    int low = 0, high = arr[0].size() - 1, strt_idx = arr[0].size();

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[row][mid] == 1)
            strt_idx = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    int cnt = arr[0].size() - strt_idx;
    return cnt;
}

int maxOnesInMatrix(vvi matrix)
{
    int one_cnt = 0, row = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        int ones_in_row_i = binarySearch(matrix, i);
        if (ones_in_row_i > one_cnt)
            one_cnt = ones_in_row_i, row = i;
    }
    cout << row << " ";
    return one_cnt;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vvi arr(n, vi(m));
        rmatrix(arr, n, m);

        cout << "\n============================================\n";
        cout << maxOnesInMatrix(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
4 3
0 1 1
0 0 1
1 1 1
0 0 1
*/