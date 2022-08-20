// Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

#include "../header.h"

void solve(vi &arr)
{
    int n = arr.size();
    sort(all(arr));
    for (int k = n - 1; k > 1; k--)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] == arr[k])
            {
                cout << arr[i] << " + " << arr[j] << " = " << arr[k] << endl;
                i++, j--;
            }
            else if (arr[i] + arr[j] < arr[k])
                i++;
            else if (arr[i] + arr[j] > arr[k])
                j--;
        }
    }
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

// 4
// 1 5 3 2

// 6
// 1 3 2 4 5 7