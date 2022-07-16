// 1. You are given a string str of digits. (will never start with a 0)
// 2. You are required to encode the str as per following rules
//     1 -> a
//     2 -> b
//     3 -> c
//     ..
//     25 -> y
//     26 -> z
// 3. You are required to calculate and print the count of encodings for the string str.

//      For 123 -> there are 3 encodings. abc, aw, lc
//      For 993 -> there is 1 encoding. iic
//      For 013 -> This is an invalid input. A string starting with 0 will not be passed.
//      For 103 -> there is 1 encoding. jc
//      For 303 -> there are 0 encodings. But such a string maybe passed. In this case
//      print 0.

#include "../header.h"

void solve()
{
    string str;
    cin >> str;
    vi dp(str.length());
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++)
    {
        if (str[i - 1] == '0' && str[i] == '0')
            dp[i] = 0;

        else if (str[i - 1] == '0' && str[i] != '0')
            dp[i] = dp[i - 1];

        else if (str[i - 1] != '0' && str[i] == '0')
        {
            if (str[i - 1] == '1' || str[i - 1] == '2')
                dp[i] = i >= 2 ? dp[i - 2] : 1;
            else
                dp[i] = 0;
        }

        else if (str[i - 1] != '0' && str[i] != '0')
        {
            int val = 0;
            string lastTwoNum = "" + str[i - 1] + str[i];
            convert(lastTwoNum, val);
            // cout << val << endl;
            if (val <= 26)
                dp[i] += dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            else
                dp[i] = dp[i - 1];
        }
    }

    cout << dp[str.length() - 1] << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
231011
? 4
*/

// 123
