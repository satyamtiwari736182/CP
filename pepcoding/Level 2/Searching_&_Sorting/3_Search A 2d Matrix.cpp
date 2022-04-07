// 1. Write an efficient algorithm that searches for a value in a m x n matrix. This matrix has the following properties:
// a). Integers in each row are sorted from left to right.
// b). The first integer of each row is greater than the last integer of the previous row.

#include "../header.h"

bool solve(vector<vi> &arr, int val)
{
    int row = -1, col = -1, low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (val >= arr[mid][0] && val <= arr[mid][arr[0].size() - 1])
        {
            row = mid;
            break;
        }
        else if (val > arr[mid][0] && val > arr[mid][arr[0].size() - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    //--------------------------------------------------
    low = 0, high = arr[0].size() - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (val == arr[row][mid])
        {
            // col = mid;
            // break;
            return true;
        }

        else if (val > arr[row][mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    // return (to_string(row) + " " + to_string(col));
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

// 5 4
// 1 3 5 7
// 10 11 16 20
// 23 30 34 60
// 62 63 65 68
// 71 72 74 80
// 65