// 1: You are given a string s that consists of lower case English letters and brackets.
// 2: Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// 3: Your result should not contain any brackets.

// Example
// (abcd) -> dcba
// (u(love)i) -> iloveu
// (gni(pc(do))ep) -> pepcoding

#include "../header.h"

string reverseParentheses(string str)
{
    string ans = "";
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == ')')
        {
            // queue<char> que;
            string str2 = "";
            while (stk.top() != '(')
            {
                // que.push(stk.top());
                str2 += stk.top();
                stk.pop();
            }

            stk.pop();

            // while (!que.empty())
            // {
            //     stk.push(que.front());
            //     que.pop();
            // }

            for (char ch2 : str2)
                stk.push(ch2);
        }

        else
            stk.push(ch);
    }

    while (!stk.empty())
    {
        ans = stk.top() + ans;
        stk.pop();
    }
    return ans;
}

void solve()
{
    string str;
    getline(cin, str);
    string result = reverseParentheses(str);
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

(gni(pc(do))ep)

*/