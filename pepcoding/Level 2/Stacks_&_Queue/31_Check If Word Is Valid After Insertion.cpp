// 1. You are given a string s determine if it is valid or not.
// 2. A valid string is a string that can be created by inserting abc at any index any number of times.

// Example:
// aabcbc can be created
// "" -> "abc" -> "aabcbc"

// while it is impossible to create abccba.

#include "../header.h"

bool isValid(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == 'c')
        {
            if (stk.size() >= 2)
            {
                char sec = stk.top();
                stk.pop();

                char fst = stk.top();
                stk.pop();

                if (sec == 'b' && fst == 'a')
                    ;
                else
                    return false;
            }
        }
        else
            stk.push(ch);
    }

    return stk.size() == 0;
}

void solve()
{
    string str;
    cin >> str;
    cout << isValid(str);
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
 aabcbc
*/
