// https://leetcode.com/problems/distinct-echo-substrings/

#include "../header.h"

ll hashVal[100000], pw[100000], r = 256;

void process(string text, int n)
{
    memset(hashVal, 0, sizeof(hashVal));
    memset(pw, 0, sizeof(pw));

    pw[0] = 1;
    for (int i = 1; i < n; i++)
    {
        hashVal[i] = (hashVal[i - 1] * r + text[i]) % mod;
        pw[i] = (pw[i - 1] * r) % mod;
    }
}

int calc(int lft, int rht)
{
    return (hashVal[rht] - hashVal[lft] * pw[rht - lft] % mod + mod) % mod;
}

int distinctEchoSubstrings(string text)
{
    int n = text.length();

    process(text, n);
    unordered_set<int> hashset; // unordered_set<string> hashset;

    for (int lenth = 1; lenth <= n / 2; lenth++)
    {
        int cnt = 0;
        for (int lft = 0, rht = lenth; rht < n; lft++, rht++)
        {
            if (text[lft] == text[rht])
                cnt++;
            else
                cnt = 0;

            if (cnt == lenth)
            {
                string str = Substr(text, lft, rht + 1);
                hashset.insert(calc(lft, rht)); // hashset.insert(str);
                cnt--;
            }
        }
    }
    return hashset.size();
}

int main()
{
    cout << "\nHello world!\n";
    string str;
    cin >> str;
    cout << "\n------------\n";
    //------------------------------------------------------
    cout << distinctEchoSubstrings(str) << endl;

    return 0;
}

/*
abcabcabc
*/
