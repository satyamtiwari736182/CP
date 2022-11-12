// 1. You are given two strings s1 and s2.
// 2. s1 represents a text and s2 represents a pattern.
// 3. You have to print the starting index for all occurrences of the pattern in the given text string.

#include "../header.h"

vi getLPS(string str) // longest prefix which is also suffix
{
    int i = 1, lenth = 0; // i dosen't backtrack.It keeps on moving forward
    vi LPS(str.length()); // uses dp-like approarch to find lps of the string.
    while (i < str.length())
    {
        if (str[i] == str[lenth])
            LPS[i++] = ++lenth;
        else
        {
            if (lenth > 0)
                lenth = LPS[lenth - 1];
            else
                LPS[i++] = 0;
        }
    }
    return LPS;
}

vi KMP(string text, string patt)
{
    string str = patt + "#" + text;
    int n = patt.length();
    vi lps = getLPS(str);
    vi ans;
    for (int i = 0; i < lps.size(); i++)
        if (lps[i] == n)
            ans.pb(i - 2 * n);
    return ans;
}

void solve()
{
    string str, patt;
    cin >> str >> patt;
    vi res = KMP(str, patt);
    parr(res, res.size());
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}
//! Time Complexity:  O(m+n)
// 2

// abab
// ab

// aabaabaab
// aab