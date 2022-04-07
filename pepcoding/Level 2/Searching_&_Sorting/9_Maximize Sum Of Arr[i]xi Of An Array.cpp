// 1. Given an array arr of N integers.
// 2. Your task is to write a program to find the maximum value of sum of arr[i]*i, where i = 0,1,2,...,n-1.
// 3. You are allowed to rearrange the elements of the array.

#include "../header.h"

int solve(vi &arr)
{
    int maxval = 0;
    sort(all(arr));
    for (int i = 0; i < arr.size(); i++)
        maxval += arr[i] * i;
    return maxval;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";

        cout << solve(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 5
// 2 3 1 5 4