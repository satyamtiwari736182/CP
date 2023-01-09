//? permutation nature
// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words (of distinct chars) by using chars of the 
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't 
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
//! Permutation method
void getWordSelection(int cc, string ustr, int ssf, int ts, vector<char> &spots)
{
    if (cc == ustr.length())
    {
        if (ssf == ts)
        {
            parr(spots, spots.size());
            cout << endl;
        }
        return;
    }

    char ch = ustr[cc];
    for (int idx = 0; idx < spots.size(); idx++)
    {
        if (spots[idx] == '\0')
        {
            spots[idx] = ch;
            getWordSelection(cc + 1, ustr, ssf + 1, ts, spots);
            spots[idx] = '\0';
        }
    }
    getWordSelection(cc + 1, ustr, ssf, ts, spots);
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

    getWordSelection(0, ustr, 0, k, spots);
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