// 1. You are given two strings s1 and s2.
// 2. You have to find the count of s2's anagrams that are present in s1.
// 3. Also, you have to print the start indices of such anagrams in s1.

// Note -> Both s1 ad s2 consist of lowercase English letters only.

#include "../header.h"
bool compare(auto pat_hashmap, auto str_hashmap)
{
    for (auto pr_str : str_hashmap)
        if (pat_hashmap[pr_str.fs] != pr_str.se)
            return false;
    return true;
}

string findAnagrams(string str, string pat)
{
    map<char, int> str_hashmap;
    map<char, int> pat_hashmap;

    for (int i = 0; i < pat.length(); i++)
        pat_hashmap[pat[i]]++;

    for (int i = 0; i < pat.length(); i++)
        str_hashmap[str[i]]++;

    int j = 0, i = pat.length(), count = 0;
    string ans = "";

    while (i < str.length())
    {
        if (compare(pat_hashmap, str_hashmap) == true)
        {
            ans = ans + to_string(j) + " ";
            count++;
        }
        char cha = str[i]; // to append
        str_hashmap[cha]++;
        char chr = str[j]; // to remove

        str_hashmap[chr]--;
        if (str_hashmap[chr] == 0)
            str_hashmap.erase(chr);

        i++;
        j++; // j is used to get start index of the anagram in the str.
    }
    cout << count << "\n";
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        string str, pat;
        cin >> str >> pat;
        cout << "\n============================================\n";
        cout << findAnagrams(str, pat);
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// cbaebabacd
// abc
vector<int> findAnagrams2(string s1, string s2) {
    vector<int> result;
    if (s2.size() > s1.size()) return result;
    
    vector<int> countS(26, 0), countP(26, 0);
    int lenS = s1.size(), lenP = s2.size();
    
    for (int i = 0; i < lenP; i++) {
        countP[s2[i] - 'a']++;
        countS[s1[i] - 'a']++;
    }
    
    for (int i = 0; i <= lenS - lenP; i++) {
        if (countP == countS) {
            result.push_back(i);
        }
        if (i + lenP < lenS) {
            countS[s1[i] - 'a']--;
            countS[s1[i + lenP] - 'a']++;
        }
    }
    
    return result;
}