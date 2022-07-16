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