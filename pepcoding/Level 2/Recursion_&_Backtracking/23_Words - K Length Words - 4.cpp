// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words by using chars of the word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.


#include "../header.h"

void getWords(int cc, string ustr, int ts, map<char, int> hashMap, string asf)
{
    if (cc > ts)
    {
        cout << asf << endl;
        return;
    }
    for (int i = 0; i < ustr.length(); i++)
    {
        char ch = ustr[i];
        if (hashMap[ch] > 0)
        {
            hashMap[ch]--;
            getWords(cc + 1, ustr, ts, hashMap, asf + ch);
            hashMap[ch]++;
        }
    }
}

void solve()
{
    string str, ustr = "";
    int k;
    cin >> str >> k;
    map<char, int> hashMap;
 
    for (char ch : str)
    {
        if (hashMap.count(ch) == 0)
            ustr += ch;
        hashMap[ch]++;
    }

    getWords(1, ustr, k, hashMap, "");
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

// aaabb
// 3