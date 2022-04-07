// 1. Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// 2. Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// 3. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// 4. Return the minimum integer k such that she can eat all the bananas within h hours.

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

// 2

// 4
// 3 6 7 11
// 8

// 5
// 30 23 15 12 29
// 10