// 1. You are given a valid parentheses string in form of A+B+C... where A, B and C are valid primitive strings.
// 2. A primitive string is a valid parentheses string which cant is split in s = x+y, with x and y nonempty valid parentheses strings.
// 3. You have to remove the outermost parentheses from all primitive strings.

// Example "(()())(())" = "(()())" + "(())".
// removing outermost parentheses from "(()())" and "(())" will result in ()()().

#include "../header.h"

string removeOuterParentheses(string str)
{
    string ans = "";
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(')
        {
            if (!stk.empty())
                ans += ch;
            stk.push(ch);
        }

        else
        {
            stk.pop();
            if (!stk.empty())
                ans += ch;
        }
    }
    return ans;
}

void solve()
{
    string str;
    getline(cin, str);
    string result = removeOuterParentheses(str);
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

(()())(())

*/
