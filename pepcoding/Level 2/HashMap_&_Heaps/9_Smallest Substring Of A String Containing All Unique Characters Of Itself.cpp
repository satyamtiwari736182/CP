// 1. You are given a string str.
// 2. You have to find the smallest window length that contains all the unique characters of the given string.


#include "../header.h"

string solution(string str)
{
    string ans = "";

    set<char> hashset;

    for (int i = 0; i < str.length(); i++)
        hashset.insert(str[i]);

    map<char, int> hashmap;
    set<char> uniqueChar;
    int i = -1, j = -1;
    int n1 = str.length();

    while (true)
    {
        bool f1 = false, f2 = false;

        // acquire
        while (i < n1 && uniqueChar.size() < hashset.size())
        {
            f1 = true;
            i++;
            char ch = str[i];
            hashmap[ch]++;
            uniqueChar.insert(ch);
        }

        // collect answers and release.
        while (j < i && uniqueChar.size() == hashset.size())
        {
            f2 = true;
            string pans = Substr(str, j + 1, i + 1);
            
            if (ans.length() == 0 || pans.length() < ans.length()) // Collecting better possible answers
                ans = pans;

            j++;
            char ch = str[j];

            // Releasing char from answer
            if (hashmap[ch] == 1)
            {
                hashmap.erase(ch);
                uniqueChar.erase(ch);
            }
            else
                hashmap[ch]--;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

int main()
{

    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        string str;
        cin >> str;
        cout << "\n============================================\n";
        cout << solution(str) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 3
// timetoperactice

// dbaecbbabdecaafbddcabba

// aaaabbbbcabbaa
