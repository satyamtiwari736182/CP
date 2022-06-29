// 1. You are given a string exp representing an expression.
// 2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
// 3. But, some of the pair of brackets maybe extra/needless.
// 4. You are required to print true if you detect extra brackets and false otherwise.

// e.g.'
// ((a + b) + (c + d)) -> false
// (a + b) + ((c + d)) -> true

#include "../header.h"

bool hasRedundant(string str)
{
    stack<char> st;
    for (char ch : str)
    {
        if (ch != ')')
            st.push(ch);
        else
        {
            if (st.top() == '(' && ch == ')')
                return true;
            while (st.top() != '(')
                st.pop();
            st.pop();
        }
    }

    return false;
}

void solve()
{
    string str;
    cin >> str;
    cout << (hasRedundant(str) ? "True" : "False") << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// (a + b) + ((c + d))