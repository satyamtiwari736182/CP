// 1. Given a string s.
// 2. Return true if the s can be palindrome after deleting at most one character from it.

#include "../header.h"

bool isPlaindrome(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] == str[j])
            i++, j--;
        else
            return false;
    }
    return true;
}

void solve()
{
    string str;
    cin >> str;
    int i = 0, j = str.length() - 1, flag = 1;
    while (i <= j)
    {
        if (str[i] == str[j])
            i++, j--;

        else
        {
            flag = isPlaindrome(str, i + 1, j) || isPlaindrome(str, i, j - 1);
            cout << (flag ? "true" : "false") << endl;
            break;
        }
    }
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
abca

*/
