// 1. You are given a string.
// 2. You have to find the count of valid substrings of the given string.
// 3. Valid substring is defined as a substring that has all unique characters.


#include "../header.h"

int solution(string str)
{
    int cntAns = 0;

    map<char, int> hashmap;
    int i = -1, j = -1;
    int n1 = str.length();

    while (true)
    {
        bool f1 = false, f2 = false;

        // acquire
        while (i < n1 - 1)
        {
            f1 = true;
            i++;
            char ch = str[i];
            hashmap[ch]++;

            if (hashmap[ch] == 2)
                break;
            else
                cntAns += (i - j);
        }

        // release.
        while (j < i)
        {
            f2 = true;
            j++;
            char ch = str[j];
            // Releasing char from answer
            hashmap[ch]--;
            if (hashmap[ch] == 1)
            {
                cntAns += (i - j);
                break;
            }
        }

        if (f1 == false && f2 == false)
            break;
    }

    return cntAns;
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

// 4
// timetoperactice

// dbaecbbabdecaafbddcabba

// aaaabbbbcabbaa

// aabcbcdbca
