// 1: Given a string S of '(' and ')' parentheses.
// 2: You need to find count of minimum number of parentheses '(' or ')' when added in any positions so that the resulting parentheses string is valid.

#include "../header.h"

int minAddTo_valid(string str)
{
    int ans = 0;
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(')
            stk.push(ch);

        else
        {
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
            else
                stk.push(ch);
        }
    }

    ans = stk.size();
    return ans;
}

void solve()
{
    string str;
    getline(cin, str);
    int result = minAddTo_valid(str);
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

()))((

*/
