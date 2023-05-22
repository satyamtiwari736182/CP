// 1. You are given an infix expression.
// 2. You are required to evaluate and print it's value.

// 1. Expression is balanced
// 2. The only operators used are +, -, *, /
// 3. Opening and closing brackets - () - are used to impact precedence of operations
// 4. + and - have equal precedence which is less than * and /. * and / also have equal precedence.
// 5. In two operators of equal precedence give preference to the one on left.
// 6. All operands are single digit numbers.

#include "../header.h"

// Priority of the operator
int precedence(char optor)
{
    if (optor == '+' || optor == '-')
        return 1;
    else if (optor == '*' || optor == '/')
        return 2;
}

int operation(int val1, int val2, char optor)
{
    if (optor == '+')
        return val1 + val2;
    else if (optor == '-')
        return val1 - val2;
    else if (optor == '*')
        return val1 * val2;
    else if (optor == '/')
        return val1 / val2;
}

void solve()
{
    string exp;
    fflush(stdin);
    getline(cin, exp);
    stack<int> oprnd;
    stack<char> optor;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '(')
            optor.push(ch);

        else if (isdigit(ch))
            oprnd.push(ch - '0'); //! use loop to get a number >= 10.

        else if (ch == ')')
        {
            while (optor.top() != '(')
            {
                char opt = optor.top();
                optor.pop();
                int val2 = oprnd.top();
                oprnd.pop();
                int val1 = oprnd.top();
                oprnd.pop();
                int val = operation(val1, val2, opt);
                oprnd.push(val);
            }
            optor.pop(); // remove the opening bracket
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (optor.empty() == false && optor.top() != '(' && precedence(ch) <= precedence(optor.top()))
            {
                char opt = optor.top();
                optor.pop();
                int val2 = oprnd.top();
                oprnd.pop();
                int val1 = oprnd.top();
                oprnd.pop();
                int val = operation(val1, val2, opt);
                oprnd.push(val);
            }
            optor.push(ch);
        }
    }

    // for the remaining operators in the stack.
    while (optor.empty() == false)
    {
        char opt = optor.top();
        optor.pop();

        int val2 = oprnd.top();
        oprnd.pop();

        int val1 = oprnd.top();
        oprnd.pop();

        int val = operation(val1, val2, opt);
        oprnd.push(val);
    }

    cout << endl;
    cout << oprnd.top() << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}
/*
2 + 6 * 4 / 8 - 3
*/

