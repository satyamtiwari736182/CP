// 1. You are given an array people where people[i] is the weight of the ith person.
// 2. You have infinite number of boats where each boat can carry a maximum weight of limit. 
// 3. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
// 4. Return the minimum number of boats to carry every given person.

#include "../header.h"

void solve()
{
    int n, wt_limit;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> wt_limit;
    sort(all(arr));
    int left = 0, right = n - 1, cnt = 0;

    while (left < right)
    {

        int sum = arr[left] + arr[right];
        if (sum <= wt_limit)
            left++, right--, cnt++;

        else if (sum > wt_limit)
            right--;
        else
            left++;
    }

    int moreCnt = n - 2 * cnt;
    if (moreCnt > 0)
        cnt += moreCnt;
    cout << cnt << endl;
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
4
3 2 2 1
3
*/
