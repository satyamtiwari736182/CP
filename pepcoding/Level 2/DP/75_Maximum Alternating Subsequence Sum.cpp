// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include "../header.h"

int memo[(int)1e5 + 4][2];
int rec(int idx, int pos, vi &nums)
{
    if (idx >= nums.size())
        return 0;
    if (memo[idx][pos] != -1)
        return memo[idx][pos];

    int ans = 0;

    // choose an element;
    if (pos == 0)
        ans = rec(idx + 1, 1, nums) + nums[idx];
    else
        ans = rec(idx + 1, 0, nums) - nums[idx];

    // won't choose the element;
    ans = max(ans, rec(idx + 1, pos, nums));
    return memo[idx][pos] = ans;
}

int tab(vi &nums)
{
    int n = nums.size();
    vi endEven(n), endOdd(n);
    endEven[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int curr = nums[i];
        endEven[i] = max(endEven[i - 1], endOdd[i - 1] + curr);
        endOdd[i] = max(endOdd[i - 1], endEven[i - 1] - curr);
    }
    return max(endEven[n - 1], endOdd[n - 1]);
}

int tab01(vi &nums)
{
    int n = nums.size();
    int endEven = 0, endOdd = 0;
    endEven = nums[0];
    for (int i = 1; i < n; i++)
    {
        int curr = nums[i];
        endEven = max(endEven, endOdd + curr);
        endOdd = max(endOdd, endEven - curr);
    }
    return max(endEven, endOdd);
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    memset(memo, -1, sizeof(memo));
    cout << "\n---------------\n";
    cout << rec(0, 0, arr) << endl;
    cout << tab(arr) << endl;
    cout << tab01(arr) << endl;
    //------------------------------------------------------
    cout << endl;
    return 0;
}

/*
4
4 2 5 3
-------
6
6 2 1 2 4 5
*/
