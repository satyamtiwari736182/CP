// 1. A conveyor belt has packages that must be shipped from one port to another within D days.
// 2. The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// 3. Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

#include "../header.h"
bool check(vi &arr, int weight, int days)
{
    int cnt_day = 1, temp_wt = 0;
    for (int wt : arr)
    {
        temp_wt += wt;
        if (temp_wt > weight)
        {
            temp_wt = wt;
            cnt_day++;
        }
    }

    return cnt_day <= days;
}

int solve(vi &arr, int m)
{
    int low = 0, high = 0, weight = 0;
    for (int i : arr)
    {
        low = max(low, i);
        high += i;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid, m) == 1)
        {
            weight = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return weight;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> d;

        cout << "\n============================================\n";

        cout << solve(arr, d);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 10
// 2 3 4 1 5 6 7 9 8 10
// 5

// 5
// 7 2 5 10 8
// 2