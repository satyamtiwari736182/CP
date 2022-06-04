// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to "next smaller element on the right" for all elements of array
// 4. Input and output is handled for you.

// "Next smaller element on the right" of an element x is defined as the first element to right of x having value smaller than x.
// Note -> If an element does not have any element on it's right side smaller than it, consider -1 as it's "next smaller element on right"
// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// Next smaller for 2 is 1
// Next smaller for 5 is 3
// Next smaller for 9 is 3
// Next smaller for 3 is 1
// Next smaller for 1 is -1
// Next smaller for 12 is 6
// Next smaller for 6 is -1
// Next smaller for 8 is 7
// Next smaller for 7 is -1

#include "../header.h"

void solve()
{
    int n, flag = -1;
    cin >> n;
    vi arr(n), nse(n);
    rarr(arr, 0, n);
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[i] <= stk.top())
            stk.pop();

        if (stk.empty())
            nse[i] = flag;
        else
            nse[i] = stk.top();

        stk.push(arr[i]);
    }

    parr(nse, n);
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

9
2 5 9 3 1 12 6 8 7

*/

// 5
// 5
// 3
// 8
// -2
// 7