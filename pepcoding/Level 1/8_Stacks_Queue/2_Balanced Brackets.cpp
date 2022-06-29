// 1. You are given a string exp representing an expression.
// 2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

// e.g.
// [(a + b) + {(c + d) * (e / f)}] -> true
// [(a + b) + {(c + d) * (e / f)]} -> false
// [(a + b) + {(c + d) * (e / f)} -> false
// ([(a + b) + {(c + d) * (e / f)}] -> false

// [(a + b) + {(c + d) * (e / f)}]

#include "../header.h"

bool isBalance(string str)
{
    stack<char> st;
    for (char ch : str)
    {

        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);

        else if (ch == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
        }

        else if (ch == '}')
        {
            if (st.empty() || st.top() != '{')
                return false;
            st.pop();
        }

        else if (ch == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;
            st.pop();
        }
    }
    if (st.size() != 0)
        return false;

    return true;
}

void solve()
{
    string str;
    cin >> str;

    cout << (isBalance(str) ? "True" : "False") << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    cin >> t;
    test(t)
        solve();
    return 0;
}
/*
2
[(a+b)+{(c+d)*(e/f)}]
[(a+b)+{(c+d)*(e/f)]}
*/