#include "../header.h"

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int dp[N][N], next[N], previous[N];
    fill(*dp, *dp + n * n, 0);

    map<char, int> hashmap;
    // 0  1  2  3  4  5  6  7  //index
    // a  b  a  c  d  a  e  a  // string
    // 2 -1  5 -1 -1  7 -1 -1 // next occurence
    //-1 -1  0 -1 -1  2 -1  5 //previus occurence
    for (int i = 0; i < n; i++)
    {
        if (hashmap.find(str[i]) == hashmap.end())
        {
            previous[i] = -1;
            hashmap.insert({str[i], i});
        }
        else
        {
            previous[i] = hashmap.at(str[i]);
            hashmap[str[i]] = i;
        }
    }
    parr(previous, n);
    cout << endl;

    hashmap.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        if (hashmap.find(str[i]) == hashmap.end())
        {
            next[i] = -1;
            hashmap.insert({str[i], i});
        }
        else
        {
            next[i] = hashmap.at(str[i]);
            hashmap[str[i]] = i;
        }
    }
    parr(next, n);
    //-----------------------------------------------------
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 1;

            else if (g == 1)
                dp[i][j] = str[i] == str[j] ? 3 : 2;

            else
            {
                if (str[i] == str[j])
                {
                    int nextidx = next[i], previdx = previous[j];
                    dp[i][j] = 2 * dp[i + 1][j - 1];

                    if (nextidx == previdx)//one a's are present btwn
                        dp[i][j] += 1;

                    else if (previdx > nextidx)//2 a's are present btwn
                        dp[i][j] -= dp[nextidx + 1][previdx - 1];

                    else//no a's are present btwn
                        dp[i][j] += 2;
                }
                else
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";

    pmatrix(dp, n, n);
    return 0;
}

// abkccbc
