// 1. Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// 2. Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
// 3. It is guaranteed that there will be an answer.

#include "../header.h"
bool check(vi &arr, int k, int h)
{
    int time = 0;
    for (int val : arr)
        time += ceil((val * 1.0) / k);
    return (time <= h);
}

int solve(vi &arr, int h)
{
    int low = 0, high = 0, k = 0;
    for (int i : arr)
        high = max(high, i);

    k = high;

    while (low <= high)
    {
        int mid = ceil((low + high) / 2.0);
        if (check(arr, mid, h) == 1)
        {
            k = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << endl;
    return k;
}
int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> k;

        cout << "\n============================================\n";

        cout << solve(arr, k);

        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 4
// 1 2 5 9
// 6