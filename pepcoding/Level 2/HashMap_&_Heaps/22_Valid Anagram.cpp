// 1. You are given two strings s1 and s2.
// 2. You have to determine if s2 is an anagram of s1.

#include "../header.h"

bool are_Anagrams(string str1, string str2)
{
    map<char, int> hashmap;
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str2.length(); i++)
        hashmap[str2[i]]++;

    for (int i = 0; i < str1.length(); i++)
        hashmap[str1[i]]--;

    for (auto pr : hashmap)
        if (pr.se != 0)
            return false;

    return true;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        string str, str2;
        cin >> str >> str2;

        cout << "\n============================================\n";
        cout << are_Anagrams(str, str2);
        cout << "\n============================================\n";
    }

    return 0;
}

// 2
// fodr
// gork

// pepcoding
// codingpep
