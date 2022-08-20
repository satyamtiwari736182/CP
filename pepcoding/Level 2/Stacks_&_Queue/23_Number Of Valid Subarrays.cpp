// Given an array nums of integers, return the number of non-empty continuous subarrays that satisfy the following condition:
// The leftmost element of the subarray is not larger than other elements in the subarray.

#include "../header.h"

int validSubaArrays(vi &nums)
{
    stack<int> stk;
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int val = nums[i];
        while (!stk.empty() && nums[stk.top()] >= val)
            stk.pop();

        int small_idx = nums.size();

        if (!stk.empty())
            small_idx = stk.top();

        ans += small_idx - i;
        stk.push(i);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    cout << validSubaArrays(arr) << endl;
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

5
1 4 2 5 3

*/