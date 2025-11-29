// 1. You are given a string.
// 2. You have to find the length of the longest substring of the given string that contains all non-repeating characters.



#include "../header.h"

string solution(string str)
{
    string ans = "";

    map<char, int> hashmap;
    int i = -1, j = -1;
    int n1 = str.length();

    while (true)
    {
        bool f1 = false, f2 = false;

        // acquire
        while (i < n1)
        {
            f1 = true;
            i++;
            char ch = str[i];
            hashmap[ch]++;
            if (hashmap[ch] == 2)
                break;
            else
            {
                string pans = Substr(str, j + 1, i + 1);
                if (ans.length() == 0 || pans.length() > ans.length()) // Collecting
                    ans = pans;
            }
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
                break;
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

// 4
// timetoperactice

// dbaecbbabdecaafbddcabba

// aaaabbbbcabbaa

// aabcbcdbca

int lengthOfLongestSubstring(String s) {
    int j=0,res=0,count[]=new int[206];
    for(int i=0;i<s.length();i++){
        count[s.charAt(i)]++;
        while(count[s.charAt(i)]>1)count[s.charAt(j++)]--;
        res=Math.max(res,i-j+1);
    }
    return res;
}


int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);
    int maxLen = 0, start = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}


