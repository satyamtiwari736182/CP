// 1. Given an array, you have to find the max sum of i*A[i] where A[i] is the element at index i in the array.
// 2. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

#include "../header.h"
int solve(vi &arr)
{
    int sum = 0, s0 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        s0 += arr[i] * i;
    }
    int maxSum = 0;
    int si = s0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int si_plus_1 = si + sum - n * arr[n - i - 1];
        maxSum = max(maxSum, si_plus_1);
        si = si_plus_1;
    }
    return maxSum;
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

// 4
// 8 3 1 2