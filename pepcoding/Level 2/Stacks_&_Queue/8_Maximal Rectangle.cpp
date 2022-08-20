// 1. Given a rows x cols binary matrix filled with 0's and 1's.
// 2. Find the largest rectangle containing only 1's and return its area.

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

int maximalRectangle(vvi &arr)
{
    vi heights(arr[0].size());
    for (int i = 0; i < heights.size(); i++)
        heights[i] = arr[0][i];
    int area = largestRectangleArea(heights);

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }
        area = max(area, largestRectangleArea(heights));
    }
    return area;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    rmatrix(arr, n, m);
    cout << "\n------------\n";
    cout << maximalRectangle(arr);
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

2
5
1 0 1 0 0
1 0 1 1 1

*/