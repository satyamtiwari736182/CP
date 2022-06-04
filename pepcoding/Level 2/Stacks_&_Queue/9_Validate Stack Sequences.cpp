// 1: Given two sequences pushed and popped with distinct values.
// 2: You have to return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack

#include "../header.h"

int validateStackSequences(vi &pushed, vi &popped)
{
    int ans = 0, j = 0;
    stack<int> stk;
    for (int ele : pushed)
    {
        stk.push(ele);
        while (!stk.empty() && stk.top() == popped[j])
        {
            stk.pop();
            j++;
        }
    }
    return j == popped.size();
}

void solve()
{
    vi pushed, popped;
    int val;
    string str;
    getline(cin, str);
    str_to_tok(str, ' ', pushed, val);
    getline(cin, str);
    str_to_tok(str, ' ', popped, val);
    bool result = validateStackSequences(pushed, popped);
    cout << result << endl;
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

1 2 3 4 5
4 5 3 2 1

*/