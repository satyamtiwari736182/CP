#include "../header.h"

bool word_mapping(string str1, vs &arr)
{
    map<char, string> hashmap;
    set<string> hashset;
    if (str1.length() != arr.size())
        return false;

    for (string str2 : arr)
        hashset.insert(str2);

    for (int i = 0; i < str1.length(); i++)
    {
        char ch1 = str1[i];
        string str = arr[i];
        if (hashmap.count(ch1) == 0 && hashset.count(str) != 0)
        {
            hashmap[ch1] = str;
            hashset.erase(str);
        }
        else if (hashmap[ch1] == str)
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        string str1;
        cin >> str1;
        vs arr(str1.length());
        for (int i = 0; i < str1.length(); i++)
            cin >> arr[i];

        cout << "\n============================================\n";
        cout << word_mapping(str1, arr);

        cout << "\n============================================\n";
    }

    return 0;
}

// 3
// abab
// pep coding pep coding

// abab
// pep coding pe coding

// ababa
// pep coding pep coding pub