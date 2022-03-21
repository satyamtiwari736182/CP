#include "../header.h"

string solution(string str1, string str2)
{
    string ans = "";

    map<char, int> hashmap2;

    for (int i = 0; i < str2.length(); i++)
    {
        char ch = str2[i];
        hashmap2[ch]++;
    }

    map<char, int> hashmap1;
    int match_cnt = 0;
    int dmct = str2.length();
    int i = -1, j = -1;
    int n1 = str1.length();
    while (true)
    {
        bool f1 = false, f2 = false;

        // acquire
        while (i < int(str1.size()) && match_cnt < dmct)
        {
            f1 = true;
            i++;
            char ch = str1[i];
            hashmap1[ch]++;

            if ((hashmap2.find(ch) != hashmap2.end()) && hashmap1[ch] <= hashmap2[ch])
                match_cnt++;
        }

        // collect answers and release.
        while (j < i && match_cnt == dmct)
        {
            f2 = true;
            string pans = Substr(str1, j + 1, i + 1);
            if (ans.length() == 0 || pans.length() < ans.length()) // Collecting better possible answers
                ans = pans;

            j++;
            char ch = str1[j];

            if (hashmap1[ch] == 1)
                hashmap1.erase(ch);
            else
                hashmap1[ch]--;

            // Releasing char from answer
            if ((hashmap2.find(ch) != hashmap2.end()) && hashmap1[ch] < hashmap2[ch])
                match_cnt--;
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
        string str1, str2;
        cin >> str1 >> str2;
        cout << "\n============================================\n";
        // unsigned ll len = 5;
        // size_t  len = 5;
        // int tmp = -1;
        // if (tmp > len)
        //     cout << ("this is crazy");
        // int i = -2;
        // while (i < -1)
        // {
        //     cout << str2;
        //     break;
        // }
        cout << solution(str1, str2) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 2
// timetopractice
// toc

// dbaecbbabdcaafbddcabba
// abbcdc
