// 1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
// 2. 'd' stands for decreasing and 'i' stands for increasing
// 3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that
// the digit decreases following a d and increases follwing an i.

// e.g.
// d -> 21
// i -> 12
// ddd -> 4321
// iii -> 1234
// dddiddd -> 43218765
// iiddd -> 126543
#include "../header.h"

void solve()
{
    string patt;
    cin >> patt;
    int val = 1, idx = 0;
    stack<int> stk;
    while (idx < patt.length())
    {
        if (patt[idx] == 'd')
            stk.push(val++);
        else
        {
            stk.push(val++);
            while (!stk.empty())
                cout << stk.top() << " ", stk.pop();
        }
        idx++;
    }
    stk.push(val);
    while (!stk.empty())
        cout << stk.top() << " ", stk.pop();
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
ddidddid
*/

// ddddiiii
