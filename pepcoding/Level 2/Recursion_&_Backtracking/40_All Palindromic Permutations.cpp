// 1. You are given a string of length n.
// 2. You have to print all the palindromic permutations of the given string.
// 3. If no palindromic permutation exists for the given string, print "-1".

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

void generateAllPalinWord(int cs, int ts, unordered_map<char, int> &fmap, char oddc, string asf)
{

    if (cs > ts)
    {
        string rev = "";
        for (int i = asf.length() - 1; i >= 0; i--)
            rev += asf[i];
        string res = asf;
        if (oddc != '\0')
            res += oddc;
        res += rev;
        cout << res << endl;
        return;
    }

    for (auto pr : fmap)
    {
        int freq = pr.se;
        char ch = pr.fs;
        if (freq > 0)
        {
            fmap[ch]--;
            generateAllPalinWord(cs + 1, ts, fmap, oddc, asf + ch);
            fmap[ch] = freq;
        }
    }
}

void solve()
{
    string str;
    cin >> str;
    unordered_map<char, int> fmap;
    for (char ch : str)
        fmap[ch]++;
    char odd = '\0';
    int odds = 0, len = 0;
    for (auto pr : fmap)
    {
        int freq = pr.se;
        char ch = pr.fs;
        if (freq % 2 == 1)
            odd = ch, odds++;
        fmap[ch] = freq / 2, len += freq / 2;
    }

    if (odds > 1)
        cout << "-1" << endl;
    else
        generateAllPalinWord(1, len, fmap, odd, "");
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
aaabb
*/