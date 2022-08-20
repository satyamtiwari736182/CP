// 1. Given a string s which represents an expression, evaluate this expression and return its value.
// 2. while dividing (/) numbers discard the decimal part.Example 3/2 should be 1 insteed of 1.5

#include "../header.h"

int calculate(string str)
{
    char sign = '+';
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            int val = 0;
            while (i < str.length() && isdigit(str[i]))
                val = val * 10 + (ch - '0'), ch = str[++i];

            i--;

            if (sign == '+')
                stk.push(val);

            else if (sign == '-')
                stk.push(-val);

            else if (sign == '*')
            {
                int ans = stk.top() * val;
                stk.pop();
                stk.push(ans);
            }

            else if (sign == '/')
            {
                int ans = stk.top() / val;
                stk.pop();
                stk.push(ans);
            }
        }

        else if (ch != ' ')
            sign = ch;
    }
    int sum = 0;
    while (!stk.empty())
        sum += stk.top(), stk.pop();
    return sum;
}

void solve()
{
    string str;
    cin >> str;
    cout << "\n------------\n";
    cout << calculate(str) << endl;
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

// 3+3/2*3-2
