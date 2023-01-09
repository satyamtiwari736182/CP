//? permutation nature
// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words (of distinct chars) by using chars of the
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
//! Combination method
void getWordSelection(int cs, string ustr, int ts, set<char> &usedChar, string asf)
{
    if (cs > ts)
    {
        cout << asf << endl;
        return;
    }
    for (int i = 0; i < ustr.length(); i++)
    {
        char ch = ustr[i];
        if (usedChar.count(ch) == false)
        {
            usedChar.insert(ch);
            getWordSelection(cs + 1, ustr, ts, usedChar, asf + ch);
            usedChar.erase(ch);
        }
    }
}

void solve()
{
    string str, ustr = "";
    int k;
    cin >> str >> k;
    set<char> uniqueSet;
    vector<char> spots(k);
    for (char ch : str)
    {
        if (uniqueSet.count(ch) == 0)
        {
            uniqueSet.insert(ch);
            ustr += ch;
        }
    }
    set<char> hashSet;
    getWordSelection(1, ustr, k, hashSet, "");
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