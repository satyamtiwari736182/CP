
// 1. You are given a string(str) and a number K.
// 2. You have to find length of the longest substring that has exactly k unique characters.
// 3. If no such substring exists, print "-1".


#include "../header.h"

int solution(string str, int k)
{
    int cntAns = 0;
    string ans = "";

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

            if (hashmap.size() < k)
                continue;
            else if (hashmap.size() == k)
            {
                int len = i - j;
                cntAns = max(cntAns, len);
                
                string pans = Substr(str, j + 1, i + 1);
                if (pans.length() > ans.length()) // Collecting better possible answers
                    ans = pans;
            }
            else
                break;
        }

        // release.
        while (j < i)
        {
            f2 = true;

            j++;
            char ch = str[j];
            // Releasing char from answer
            if (hashmap[ch] == 1)
                hashmap.erase(ch);
            else
                hashmap[ch]--;

            if (hashmap.size() > k)
                continue;
            else if (hashmap.size() == k)
            {
                int len = i - j;
                cntAns = max(cntAns, len);

                string pans = Substr(str, j + 1, i + 1);
                if (pans.length() > ans.length()) // Collecting better possible answers
                    ans = pans;
                break;
            }
        }

        if (f1 == false && f2 == false)
            break;
    }
    cout << ans << "  ";
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
        int k;
        cin >> str >> k;
        cout << "\n============================================\n";
        cout << solution(str, k) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// aabcbcdbca 3