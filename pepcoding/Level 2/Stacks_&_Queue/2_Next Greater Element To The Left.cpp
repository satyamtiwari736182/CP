// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to find "next greater element on the left" for all elements of array
// 4. Input and output is handled for you.

// "Next greater element on the left" of an element x is defined as the first element to left of x having value greater than x.
// Note -> If an element does not have any element on it's left side greater than it, consider -1 as it's "next greater element on left"
// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// Next greater for 2 is -1
// Next greater for 5 is -1
// Next greater for 9 is -1
// Next greater for 3 is 9
// Next greater for 1 is 3
// Next greater for 12 is -1
// Next greater for 6 is 12
// Next greater for 8 is 12
// Next greater for 7 is 8

#include "../header.h"

void solve()
{
    int n, flag = -1;
    cin >> n;
    vi arr(n), nge(n);
    rarr(arr, 0, n);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[i] >= stk.top())
            stk.pop();

        if (stk.empty())
            nge[i] = flag;
        else
            nge[i] = stk.top();

        stk.push(arr[i]);
    }

    parr(nge, n);
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