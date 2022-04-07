// 1. Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:
// a). Integers in each row are sorted in ascending from left to right.
// b). Integers in each column are sorted in ascending from top to bottom.

#include "../header.h"

bool solve(vector<vi> &arr, int val)
{
    int row = 0, col = arr[0].size() - 1;
    while (row < arr.size() && col >= 0)
    {
        if (val == arr[row][col])
            return true;
        else if (val > arr[row][col])
            row++;
        else
            col--;
    }

    return false;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, val;
        cin >> m >> n;
        vector<vi> arr(m);
        rvmatrix(arr, m, n);
        cin >> val;
        cout << "\n============================================\n";
        cout << solve(arr, val);
        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 5 5
// 1 4 7 11 15
// 2 5 8 12 20
// 4 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30
// 12