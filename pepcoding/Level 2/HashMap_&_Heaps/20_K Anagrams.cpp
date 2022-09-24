// 1. You are given two strings s1, s2, and a number K.
// 2. You have to find if two strings are K-anagrams of each other or not.
// 3. Two strings are called K-anagrams if 
//    -> Both s1 and s2 have the same number of characters.
//    -> After changing K characters in any string, s1 and s2 become anagram of each other. 

// Note -> Both s1 ad s2 consist of lowercase English letters only.


#include "../header.h"

bool are_K_Anagrams(string str1, string str2, int k)
{
    map<char, int> hashmap;
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length(); i++)
        hashmap[str1[i]]++;

    for (int i = 0; i < str2.length(); i++)
    {
        char ch = str2[i];
        if (hashmap[ch] > 0)
            hashmap[ch]--;
    }

    int count = 0;
    for (auto pr : hashmap)
        count += pr.se;
    if (count > k)
        return false;
        
    return true;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t, k;
    cin >> t;
    test(t)
    {
        string str, str2;
        cin >> str >> str2;
        cin >> k;
        cout << "\n============================================\n";
        cout << are_K_Anagrams(str, str2, k);
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// fodr
// gork
// 2
