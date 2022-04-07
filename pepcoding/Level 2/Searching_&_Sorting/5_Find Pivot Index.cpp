// 1. Given an array of integers nums, calculate the pivot index of this array.
// 2. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// 3. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// 4. Return the leftmost pivot index. If no such index exists, return -1.

#include "../header.h"

int solve(vi &arr)
// Also known as eqilibrium point.
{
    int total_sum = 0, left_sum = 0;

    for (int val : arr)
        total_sum += val;

    for (int i = 0; i < arr.size(); i++)
    {
        int right_sum = total_sum - left_sum - arr[i];
        if (left_sum == right_sum)
            return i;
        left_sum += arr[i];
    }

    return -1;
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

// 6
// 1 7 3 6 5 6