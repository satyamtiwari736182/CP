// Given a balanced parentheses string S, compute the score of the string based on the following rule:
//     () has score 1
//     AB has score A + B, where A and B are balanced parentheses strings.
//     (A) has score 2 * A, where A is a balanced parentheses string.

// Score of ()()() string is 3 => 1 + 1 + 1
// Score of (()) string is 2 => 2 * 1

#include "../header.h"

int scoreParentheses(string str)
{
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(')
            stk.push(-1); //( => -1    represented

        else
        {
            if (stk.top() == -1)
            {
                stk.pop();
                stk.push(1);
            }

            else
            {
                int val = 0;
                while (stk.top() != -1)
                {
                    val += stk.top();
                    stk.pop();
                }

                stk.pop();

                stk.push(2 * val);
            }
        }
    }

    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

void solve()
{
    string str;
    getline(cin, str);
    int result = scoreParentheses(str);
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

(()(()))

*/
