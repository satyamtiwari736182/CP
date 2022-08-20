// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the height of bars in a bar chart.
// 3. You are required to find and print the area of largest rectangle in the histogram.

// Challenge. Could u solve it in one iteration.
// Note. This question is same as Largest Area Histogram just the constrains are higher.

#include "../header.h"

int largestRectangleArea(vi &heights)
{
    stack<int> stk;
    stk.push(-1);
    int maxArea = 0;
    for (int i = 0; i <= heights.size(); i++)
    {
        int val = (i == heights.size() ? 0 : heights[i]);
        while (stk.top() != -1 && heights[stk.top()] >= val)
        {
            int rightMin = i;
            int height = heights[stk.top()];
            stk.pop();
            int leftMin = stk.top();
            maxArea = max(maxArea, (rightMin - leftMin - 1) * height);
        }
        stk.push(i);
    }
    return maxArea;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    cout << largestRectangleArea(arr);
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

6
2 1 5 6 2 3

*/