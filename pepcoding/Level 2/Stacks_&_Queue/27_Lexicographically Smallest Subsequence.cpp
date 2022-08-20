// 1. Given an integer array nums and a positive integer k;
// 2. return the lexicographically smallest subsequence of size k;

#include "../header.h"

void smallestSubset(vi &nums, int k)
{
    stack<int> stk;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int val = nums[i];
        while (!stk.empty() && val < stk.top() && n - i - 1 >= k - stk.size())
            stk.pop();

        if (stk.size() < k)
            stk.push(val);
    }

    vi ans(k);
    for (int i = k - 1; i >= 0; i--)
        ans[i] = stk.top(), stk.pop();

    for (int val : ans)
        cout << val << " ";
}

void solve()
{
    int n, k;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> k;
    smallestSubset(arr, k);
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
2 4 3 3 5 4 9 6
4
*/