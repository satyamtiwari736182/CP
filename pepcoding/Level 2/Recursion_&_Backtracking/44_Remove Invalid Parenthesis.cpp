// 1. You are given a string, which represents an expression having only opening and closing parenthesis.
// 2. You have to remove minimum number of parenthesis to make the given expression valid.
// 3. If there are multiple answers, you have to print all of them.

// Note -> Check out the question video and write the recursive code as it is intended without changing signature. The judge can't
//                force you but intends you to teach a concept.

#include "../header.h"

int getMin(string str)
{
    stack<char> stk;
    for (char ch : str)
    {
        if (ch == '(')
            stk.push(ch);
        else if (ch == ')')
        {
            if (stk.empty())
                stk.push(ch);
            else if (stk.top() == ')')
                stk.push(ch);
            else if (stk.top() == '(')
                stk.pop();
        }
    }
    return stk.size();
}

void solution(string str, int mra, unordered_set<string> res)
{
    if (mra == 0)
    {
        int mrnow = getMin(str);
        if (mrnow == 0)
            if (!res.count(str))
                cout << str << endl, res.insert(str);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        string left = Substr(str, 0, i);
        string right = str.substr(i + 1);
        solution(left + right, mra - 1, res);
    }
}

void solve()
{
    string str;
    cin >> str;
    unordered_set<string> res;
    int mr = getMin(str);
    // cout <<
    solution(str, mr, res);
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

// ()())()