// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 2. You are required to generate and print all ways you can select k distinct characters out of the
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
//! Combination Method
void getWordSelection(int cc, string ustr, int ssf, int ts, string asf) // cc => current boxes
{
    if (cc == ustr.length())
    {
        if (ssf == ts)
            cout << asf << endl;
        return;
    }
    char ch = ustr[cc];
    getWordSelection(cc + 1, ustr, ssf + 1, ts, asf + ch);
    getWordSelection(cc + 1, ustr, ssf, ts, asf);
}

void solve()
{
    string str, ustr = "";
    int k;
    cin >> str >> k;
    set<char> uniqueSet;
    for (char ch : str)
    {
        if (uniqueSet.count(ch) == 0)
        {
            uniqueSet.insert(ch);
            ustr += ch;
        }
    }
    getWordSelection(0, ustr, 0, k, "");
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

// aabbbccdde
// 3