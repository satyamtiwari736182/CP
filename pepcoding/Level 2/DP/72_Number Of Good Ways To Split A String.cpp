// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

#include "../header.h"

int numSplits(string str)
{
    int n = str.length();
    int *prefix = new int[n];
    int *suff = new int[n];
    int *freq = new int[26];
    memset(prefix, 0, sizeof(prefix));
    memset(suff, 0, sizeof(suff));
    memset(freq, 0, sizeof(freq));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int ch = str[i] - 'a';
        freq[ch]++;
        if (freq[ch] == 1)
            cnt++;
        prefix[i] = cnt;
    }

    memset(freq, 0, sizeof(freq));
    cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int idx = str[i] - 'a';
        freq[idx]++;
        if (freq[idx] == 1)
            cnt++;
        suff[i] = cnt;
    } 

    int splits = 0;

    for (int i = 0; i < n - 1; i++)
        if (prefix[i] == suff[i + 1])
            splits++;

    return splits;
}

int main()
{
    cout << "\nHello world!\n";
    string str;
    cin >> str;
    cout << "\n------------\n";
    cout << numSplits(str) << endl;

    //------------------------------------------------------
    cout << endl;
    return 0;
}

/*
aacaba
-------
acbadbaada
*/
