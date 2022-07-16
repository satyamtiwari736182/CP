// 1. You are given a number n, representing the number of people in a party.
// 2. You are given n strings of n length containing 0's and 1's
// 3. If there is a '1' in ith row, jth spot, then person i knows about person j.
// 4. A celebrity is defined as somebody who knows no other person than himself but everybody else knows him.
// 5. If there is a celebrity print it's index otherwise print "none".

// Note -> There can be only one celebrity. Think why?

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    rmatrix(arr, n, n);
    cout << "\n**************\n";

    stack<int> stk;
    for (int i = 0; i < n; i++)
        stk.push(i);
    while (stk.size() > 1)
    {
        int val1 = stk.top();
        stk.pop();
        int val2 = stk.top();
        stk.pop();
        if (arr[val1][val2])
            stk.push(val2);
        else
            stk.push(val1);
    }

    int celi = stk.top();
    int celib = stk.top() + 1;
    for (int i = 0; i < n; i++)
    {
        if (i != celi && arr[i][celi] == 0)
        {
            celib = -1;
            break;
        }

        if (i != celi && arr[celi][i] == 1)
        {
            celib = -1;
            break;
        }
    }
    cout << celib << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}
/*
4
0 0 0 0
1 0 1 1
1 1 0 1
1 1 1 0
*/