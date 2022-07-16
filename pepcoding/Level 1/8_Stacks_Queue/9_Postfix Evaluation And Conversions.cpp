// 1. You are given a postfix expression.
// 2. You are required to evaluate it and print it's value.
// 3. You are required to convert it to infix and print it.
// 4. You are required to convert it to prefix and print it.
// Note -> Use brackets in infix expression for indicating precedence. Check sample input output for more details.

#include "../header.h"

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

void process(char opt, stack<string> &prefix, stack<string> &infix, stack<int> &eva)
{

    string val2 = prefix.top();
    prefix.pop();
    string val1 = prefix.top();
    prefix.pop();

    string str = "";
    str += opt;
    prefix.push(str + val1 + val2);
    //***************************************
    val2 = infix.top();
    infix.pop();
    val1 = infix.top();
    infix.pop();

    str = "";
    str += opt;
    infix.push("(" + val1 + str + val2 + ")");
    //***************************************
    int v2 = eva.top();
    eva.pop();
    int v1 = eva.top();
    eva.pop();
    int val = operation(v1, v2, opt);
    eva.push(val);
}

void solve()
{
    string exp;
    fflush(stdin);
    getline(cin, exp);
    stack<string> prefix, infix;
    stack<char> optor;
    stack<int> eva;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            string str = "";
            str += ch;
            prefix.push(str), infix.push(str), eva.push(ch - '0');
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            process(ch, prefix, infix, eva);
    }

    cout << endl;
    cout << prefix.top() << endl;
    cout << infix.top() << endl;
    cout << eva.top() << endl;
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
264*8/+3-
*/