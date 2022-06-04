// 1. Given a string s, remove duplicate letters so that every letter appears once and only once.
// 2. You must make sure your result is the first in dictionary order among all possible results.


#include "../header.h"

string removeDuplicate(string str)
{
    stack<char> stk;
    vi freq(26), exist(26);

    for (char ch : str)
        freq[ch - 'a']++;

    for (char ch : str)
    {
        freq[ch - 'a']--;

        if (exist[ch - 'a'])
            continue;

        while (!stk.empty() && stk.top() > ch && freq[stk.top() - 'a'] > 0)
        {
            char temp = stk.top();
            stk.pop();
            exist[temp - 'a'] = false;
        }

        stk.push(ch);
        exist[ch - 'a'] = true;
    }

    string ans = "";
    while (!stk.empty())
        ans = stk.top() + ans, stk.pop();

    return ans;
}

void solve()
{
    string str;
    cin >> str;

    fflush(stdin);
    string res = removeDuplicate(str);
    cout << res << endl;
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

bcabc

*/