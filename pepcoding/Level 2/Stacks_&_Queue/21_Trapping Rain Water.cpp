// 1. Given n non-negative integers representing an elevation map where the width of each bar is 1.
// 2. Compute how much water it can trap after raining.

#include "../header.h"

int rainWaterTrapping_I(vi &height)
{
    stack<int> stk;
    int ans = 0;
    for (int i = 0, n = height.size(); i < n; i++)
    {
        while (!stk.empty() && height[stk.top()] <= height[i])
        {
            int rightMax = i;

            int currHeight = height[stk.top()];
            stk.pop();

            if (stk.empty())
                break;
            int leftMax = stk.top();
            int width = rightMax - leftMax - 1;
            ans += (min(height[rightMax], height[leftMax]) - currHeight) * width;
        }
        stk.push(i);
    }
    return ans;
}

int rainWaterTrapping_II(vi &height)
{
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, ans = 0;
    while (left < right)
    {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (leftMax < rightMax)
            ans += leftMax - height[left], left++;
        else
            ans += rightMax - height[right], right--;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << rainWaterTrapping_II(arr) << endl;
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
12
0 1 0 2 1 0 1 3 2 1 2 1
*/