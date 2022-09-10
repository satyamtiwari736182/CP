// 1. You are given n space-separated strings, which represents a dictionary of words.
// 2. You are given another string that represents a sentence.
// 3. You have to determine if this sentence can be segmented into a space-separated sequence of one or more dictionary words.

#include "../header.h"

bool solution(string sentence, unordered_set<string> &dictionary)
{
    vi dp(sentence.length());
    for (int i = 0; i < sentence.length(); i++)
        for (int j = 0; j < i; j++)
        {
            string word2check = Substr(sentence, j, i + 1);
            if (dictionary.count(word2check) == true)
            {
                if (j > 0)
                    dp[i] += dp[j - 1];
                else
                    dp[i] += 1;
            }
        }

    parr(dp, dp.size());
    cout << endl;
    return dp[sentence.length() - 1] > 0;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    unordered_set<string> dictionary;
    string str;
    while (n-- > 0)
    {
        cin >> str;
        dictionary.insert(str);
    }
    cin >> str;

    cout << "\n------------\n";
    cout << solution(str, dictionary) << endl;

    //------------------------------------------------------

    return 0;
}

/*
10
loves pep coding pepcoding ice cream icecream man go mango;
pepcodinglovesmangoicecream
*/
