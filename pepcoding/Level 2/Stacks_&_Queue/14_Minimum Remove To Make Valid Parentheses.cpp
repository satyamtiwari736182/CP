// 1: Given a string s of '(' , ')' and lowercase English characters
// 2: Your task is to remove the minimum number of parentheses ( '(' or ')') so that the resulting parentheses string is valid and return it.
// 3: In case of multiple valid strings give precedence in keeping innermost parenthesis.

// example
// (a(b(c)d) this string has (a(bc)d), (ab(c)d) and a(b(c)d) 3 valid strings.
// Among all 3 valid strings a(b(c)d) has the innermost parentheses.


#include "../header.h"

string reverseParentheses(string str)
{
    string ans = "";
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(')
            stk.push(i);
        else if (ch == ')')
        {
            if (stk.empty())
                str[i] = '.';
            else
                stk.pop();
        }
    }

    while (!stk.empty())
    {
        str[stk.top()] = '.';
        stk.pop();
    }

    for (char ch : str)
        if (ch != '.')
            ans += ch;

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

a)b(c)d

*/
