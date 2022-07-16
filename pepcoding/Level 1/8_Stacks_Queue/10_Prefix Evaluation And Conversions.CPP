// 1. You are given a prefix expression.
// 2. You are required to evaluate it and print it's value.
// 3. You are required to convert it to infix and print it.
// 4. You are required to convert it to postfix and print it.

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

void process(char opt, stack<string> &postfix, stack<string> &infix, stack<int> &eva)
{

    string val1 = postfix.top();
    postfix.pop();
    string val2 = postfix.top();
    postfix.pop();

    string str = "";
    str += opt;
    postfix.push(val1 + val2 + str);
    //***************************************
    val1 = infix.top();
    infix.pop();
    val2 = infix.top();
    infix.pop();

    str = "";
    str += opt;
    infix.push("(" + val1 + str + val2 + ")");
    //***************************************
    int v1 = eva.top();
    eva.pop();
    int v2 = eva.top();
    eva.pop();
    int val = operation(v1, v2, opt);
    eva.push(val);
}

void solve()
{
    string exp;
    fflush(stdin);
    getline(cin, exp);
    stack<string> postfix, infix;
    stack<char> optor;
    stack<int> eva;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            string str = "";
            str += ch;
            postfix.push(str), infix.push(str), eva.push(ch - '0');
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            process(ch, postfix, infix, eva);
    }

    cout << endl;
    cout << postfix.top() << endl;
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
-+2/*6483
*/

// -+2/*6483
