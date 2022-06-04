// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

#include "../header.h"

void solve()
{
    string str;
    int val;

    vi arr;
    getline(cin, str);
    str_to_tok(str, ' ', arr, val);

    int n = arr.size(), flag = -1;
    stack<int> stk;
    vi nge(n);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!stk.empty() && arr[i] >= stk.top())
            stk.pop();

        stk.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {

        while (!stk.empty() && arr[i] >= stk.top())
            stk.pop();

        if (stk.empty())
            nge[i] = flag;
        else
            nge[i] = stk.top();

        stk.push(arr[i]);
    }

    for (int x : nge)
        cout << x << " ";
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

1 3 4 2

*/

// 3
// 1
// 2
// 1