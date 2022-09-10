// 1. You are given a string.
// 2. You have to find the index of the first non-repeating character in the given string.
// 3. If no such character exists, print "-1".

#include "../header.h"
#include <cstring>

int solve(string str)
{
    unordered_map<char, int> freqMap;
    for (char ch : str)
        freqMap[ch]++;

    for (int i = 0; i < str.length(); i++)
        if (freqMap[str[i]] == 1)
            return i;

    return -1;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        string str;
        fflush(stdin), getline(cin, str);

        cout << "\n============================================\n";
        cout << solve(str);
        cout << "\n============================================\n";
    }

    return 0;
}

// pepcoding