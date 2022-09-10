// 1. Given a list of strings words and a string pattern.
// 2. Return a list of words[i] that match pattern. You may return the answer in any order.
// 3. A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
// 4. Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

#include "../header.h"

bool isMatching(string word, string patt)
{
    unordered_map<char, char> hashmap; // patt char => word char
    for (int i = 0; i < patt.length(); i++)
    {
        char wch = word[i], pch = patt[i];
        if (hashmap.count(pch) == true)
        {
            if (hashmap[pch] != wch)
                return false;
        }

        else
            hashmap[pch] = wch;
    }
    return true;
}

vs findAndReplacePatt(vs &words, string patt)
{
    vs res;
    for (string word : words)
        if (isMatching(word, patt))
            res.pb(word);
    return res;
}

void solve()
{
    string patt;
    cin >> patt;
    int n;
    cin >> n;
    vs arr(n);
    rarr(arr, 0, n);
    cout << "--------------------" << endl;
    vs res = findAndReplacePatt(arr, patt);
    parr(res, res.size());
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
epp
6
mno rst rss bll lml aaa
*/
