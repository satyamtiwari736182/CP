// 1. Given an integer array nums of length n where all the integers of nums are in the range [1, n].
// 2. Each integer appears once or twice, return an array of all the integers that appears twice.
// 3. You must write an algorithm that runs in O(n) time and uses only constant extra space.

#include "../header.h"
vi findDuplicates(vi &nums)
{
    vi res;
    for (int i = 0; i < nums.size(); i++)
    {
        int idx = abs(nums[i]) - 1;
        int val = nums[idx];
        if (val < 0)
            res.pb(idx + 1);
        else
            nums[idx] = -nums[idx];
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "--------------------" << endl;
    vi res = findDuplicates(arr);
    parr(res, res.size());
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
8
4 3 2 7 8 2 3 1
*/
