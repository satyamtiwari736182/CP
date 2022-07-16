// 1. You are given an infix expression.
// 2. You are required to convert it to postfix and print it.
// 3. You are required to convert it to prefix and print it.

#include "../header.h"

// Priority of the operator
int precedence(char optor)
{
    if (optor == '+' || optor == '-')
        return 1;
    else if (optor == '*' || optor == '/')
        return 2;
    else
        return 0;
}

void process(stack<char> &optor, stack<string> &prefix, stack<string> &postfix)
{
    char opt = optor.top();
    optor.pop();
    string val2 = prefix.top();
    prefix.pop();
    string val1 = prefix.top();
    prefix.pop();
    string str = "";
    str += opt;
    prefix.push(str + val1 + val2);
    //***************************************
    val2 = postfix.top();
    postfix.pop();
    val1 = postfix.top();
    postfix.pop();
    str = "";
    str += opt;
    postfix.push(val1 + val2 + str);
}

void solve()
{
    string exp;
    fflush(stdin);
    getline(cin, exp);
    stack<string> prefix, postfix;
    stack<char> optor;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '(')
            optor.push(ch);

        else if (isdigit(ch) || isalpha(ch))
        {
            string str = "";
            str += ch;
            prefix.push(str), postfix.push(str);
        }

        else if (ch == ')')
        {
            while (optor.top() != '(')
                process(optor, prefix, postfix);

            optor.pop(); // remove the opening bracket
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (optor.empty() == false && optor.top() != '(' && precedence(ch) <= precedence(optor.top()))
                process(optor, prefix, postfix);

            optor.push(ch);
        }
    }

    // for the remaining operators in the stack.
    while (optor.empty() == false)
        process(optor, prefix, postfix);

    cout << endl;
    cout << prefix.top() << endl;
    cout << postfix.top() << endl;
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

a*(b-c+d)/e
*/