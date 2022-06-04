// Given string num representing a non-negative integer num, and an integer k, print the smallest possible integer after removing k digits from num.

#include "../header.h"

string getMin(string num, int k)
{
    stack<char> stk;
    for (char ch : num)
    {
        while (!stk.empty() && k > 0 && stk.top() > ch)
            stk.pop(), k--;
        stk.push(ch);
    }

    while (!stk.empty() && k > 0)
        stk.pop();

    string ans = "";
    while (!stk.empty())
        ans = stk.top() + ans, stk.pop();

    return ans;
}

void solve()
{
    string num;
    cin >> num;
    int n;
    fflush(stdin);
    cin >> n;
    string res = getMin(num, n);
    cout << res << endl;
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

1432219
3

*/