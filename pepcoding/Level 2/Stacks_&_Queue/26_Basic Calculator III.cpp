// 1. Implement a basic calculator to evaluate a simple expression string.
// 2. String will contain only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'.
// 3. All intermediate results will be in the range of [-2^31, 2^31 - 1].

#include "../header.h"

struct Pair
{
    stack<int> stk;
    char sign;
};

void calc(stack<int> &stk, int val, char sign)
{
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

int calculate(string str)
{
    char sign = '+';
    stack<Pair> stkP;
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

            calc(stk, val, sign);
        }

        else if (ch == '(')
        {
            stkP.push({stk, sign}), sign = '+';
            stack<int> nstk;
            stk = nstk;
        }

        else if (ch == ')')
        {
            int val = 0;

            while (!stk.empty())
                val += stk.top(), stk.pop();

            Pair temp = stkP.top();
            stkP.pop();
            stk = temp.stk, sign = temp.sign;
            calc(stk, val, sign);
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

// 2*(5+5*2)/3+(6/2+8)
