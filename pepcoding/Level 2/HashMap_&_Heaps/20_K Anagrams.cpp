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
