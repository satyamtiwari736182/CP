// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 2. You are required to generate and print all ways you can select k distinct characters out of the 
//      word.
 
// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't 
//                force you but the intention is to teach a concept. Play in spirit of the question.


#include "../header.h"

void getWordSelection(int cc, string ustr, int lc_idx, int ts, string asf)
{
    if (cc > ts)
    {
        cout << asf << endl;
        return;
    }

    for (int idx = lc_idx + 1; idx < ustr.length(); idx++)
    {
        char ch = ustr[idx];
        getWordSelection(cc + 1, ustr, idx, ts, asf + ch);
    }
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

    getWordSelection(1, ustr, -1, k, "");
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