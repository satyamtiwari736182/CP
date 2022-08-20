// Given a string s representing an expression, implement a basic calculator to evaluate it.

#include "../header.h"

int calculate(string str)
{
    int sum = 0, sign = 1;
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            int val = 0;
            while (i < str.length() && isdigit(str[i]))
                val = val * 10 + (str[i] - '0'), i++;
            i--;
            val = val * sign, sum += val;
            sign = +1;
        }

        else if (ch == '(')
            stk.push(sum), stk.push(sign), sum = 0, sign = +1;
        else if (ch == ')')
            sum *= stk.top(), stk.pop(), sum += stk.top(), stk.pop();
        else if (ch == '-')
            sign *= -1;
    }
    
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
/*
(1+(4+5+2)-3)+(6+8)
*/
