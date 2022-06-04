// 1. Given an unsorted array 'arr'.
// 2. Reorder it in-place such that :  arr[0] <= arr[1] >= arr[2] <= arr[3] . . . .
// 3. Please sort the array in place and do not define additional arrays.
// 4. Allowed Time Complexity : O(n)

#include "../header.h"

void solve()
{
    int arr[100], n;
    cin >> n;
    rarr(arr, 0, n);

    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)//even
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }

        else//odd
        {
            if (arr[i] < arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }

    parr(arr, n);
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

6
3 5 2 1 6 4

*/
