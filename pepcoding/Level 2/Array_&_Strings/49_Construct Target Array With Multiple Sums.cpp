// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include "../header.h"

bool isPossible(vi &arr)
{
    int sum = 0;
    priority_queue<int> pque;
    for (int ele : arr)
        sum += ele, pque.push(ele);

    while (pque.top() != 1)
    {
        int topVal = pque.top();
        pque.pop();
        sum -= topVal;
        if (sum <= 0 || sum >= topVal)
            return false;
        topVal -= sum;
        pque.push(topVal);
        sum += topVal;
    }

    // while (!pque.empty())
    //     cout << pque.top() << " ", pque.pop();
    // cout << endl;

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "--------------------" << endl;
    cout << isPossible(arr);
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
3
9 3 5
---------
4
1 1 1 2
---------
5
1 5 9 17 1
*/
