// Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.

#include "../header.h"

void solve(vi &arr)
{
    int n = arr.size();
    sort(all(arr));
    int cnt = 0;

    for (int k = n - 1; k > 1; k--)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] > arr[k])
                cnt += j - i, j--;
            else if (arr[i] + arr[j] <= arr[k])
                i++;
        }
    }
    cout << cnt << endl;
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
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";

        solve(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 5
// 6 4 9 7 8

// 5
// 6 8 4 2 9