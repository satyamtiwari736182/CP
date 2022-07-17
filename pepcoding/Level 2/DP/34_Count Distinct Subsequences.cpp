// 1. You are given a string.
// 2. You have to print the count of distinct and non-empty subsequences of the given string.

// Note -> String contains only lowercase letters.

#include "../header.h"

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int dp[n + 1];
    fill(dp, dp + n + 1, 0);

    map<char, int> hashmap;

    dp[0] = 1;
    //-----------------------------------------------------
    for (int i = 0; i < n; i++)
    {
        if (hashmap.find(str[i]) != hashmap.end())
        {
            dp[i + 1] = 2 * dp[i] - dp[hashmap.at(str[i])];
            hashmap[str[i]] = i;
        }
        else
        {
            dp[i + 1] = 2 * dp[i];
            hashmap[str[i]] = i;
        }
    }
    //-----------------------------------------------------

    cout << "\nHello world!\n";

    parr(dp, n + 1);
    return 0;
}

// abcbac

// abc