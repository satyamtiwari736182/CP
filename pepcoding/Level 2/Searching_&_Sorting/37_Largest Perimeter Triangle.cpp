// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

#include "../header.h"

int largetsPerimeterTriangle(vi &arr)
{
    int perimeter = 0;
    sort(all(arr));
    for (int i = arr.size() - 1; i >= 2; i--)
        if (arr[i - 2] + arr[i - 1] > arr[i])
            perimeter = max(perimeter, arr[i - 2] + arr[i - 1] + arr[i]);
    return perimeter;
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
        vi arr(n);
        rarr(arr, 0, n);

        cout << "\n============================================\n";
        cout << largetsPerimeterTriangle(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
5
34 5 3 30 9
*/

// 4
// 3 6 2 3