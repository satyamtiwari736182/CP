// 1. There is an integer array nums sorted in ascending order (with distinct values).
// 2. nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// 3. Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// 4. You must write an algorithm with O(log n) runtime complexity.

#include "../header.h"
int solve(vi &arr, int val)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (val == arr[mid])
            return mid;
        else if (arr[low] <= arr[mid])
        {
            // low to mid is sorted.
            if (val >= arr[low] && val < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (arr[mid] <= arr[high])
        {
            // mid to high is sorted
            if (val > arr[mid] && val <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
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
        int n, val;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> val;
        cout << "\n============================================\n";

        cout << solve(arr, val);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 7
// 4 5 6 7 0 1 2
// 1

// 9
// 4 5 6 7 8 9 10 1 2
// 1