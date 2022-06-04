// 1. A string 's' of lowercase English letters is given. 
// 2. We want to partition this string into as many parts as possible so that each letter appears in at most one part.
// 3. Return a list of integers representing the size of these parts.

#include "../header.h"

void solve()
{
    string str;
    cin >> str;
    map<char, int> hashmap;

    for (int i = 0; i < str.length(); i++)
        hashmap[str[i]] = i;

    int lastIdx = 0, prevPart_idx = 0, i = 0;

    while (i < str.length())
    {
        for (; i <= lastIdx; i++)
            lastIdx = max(lastIdx, hashmap[str[i]]);

        cout << (i - prevPart_idx) << " ";
        prevPart_idx = i;

        i++;
        lastIdx = i;
    }
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
ababcbacadefegdehijhklij

*/
