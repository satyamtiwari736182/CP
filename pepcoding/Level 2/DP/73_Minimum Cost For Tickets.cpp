// 1. You are going on a vacation for a year, you've decided certain days for travelling in the city, given to you as a strictly increasing array from day 1....365
//  2. There are 3 kinds of passes you can take in this city for transport:
//      a) A single day pass, cost of which is in an array at cost[0]
//      b) A week's pass, cost of which  is in an array at cost[1]
//      c) A month's pass, cost of which  is in an array at cost[2]
//  3. Find and return minimum amount it'll cost you for travelling in the city according to the given days
//  4. Input and output is handled for you
//  5. It is a functional problem ,please do not modify main()

#include "../header.h"

bool willTravelToday(int cday, vi &days)
{
    for (int i = 0; i < days.size(); i++)
        if (days[i] == cday)
            return true;
    return false;
}

int rec(int cday, vi &costs, vi &days)
{
    if (cday > days[days.size() - 1])
        return 0;
    int ans = (int)1e8;
    if (willTravelToday(cday, days))
    {
        ans = rec(cday + 1, costs, days) + costs[0];
        ans = min(ans, rec(cday + 7, costs, days) + costs[1]);
        ans = min(ans, rec(cday + 30, costs, days) + costs[2]);
    }
    else
        return rec(cday + 1, costs, days);
    return ans;
}

int tab(vi &costs, vi &days)
{
    int dp[400];
    memset(dp, -1, sizeof(dp));
    for (int cday = 399; cday >= 0; cday--)
    {
        if (cday > days[days.size() - 1])
        {
            dp[cday] = 0; // return 0;
            continue;
        }

        int ans = (int)1e8;
        if (willTravelToday(cday, days))
        {
            ans = dp[cday + 1] + costs[0];            // rec(cday + 1, costs, days) + costs[0];
            ans = min(ans, dp[cday + 7] + costs[1]);  // min(ans, rec(cday + 7, costs, days) + costs[1]);
            ans = min(ans, dp[cday + 30] + costs[2]); // min(ans, rec(cday + 30, costs, days) + costs[2]);
            dp[cday] = ans;
        }
        else
            dp[cday] = dp[cday + 1]; // return rec(cday + 1, costs, days);
    }
    return dp[1];
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi costs(n), days(n);
    rarr(days, 0, n);
    rarr(costs, 0, 3);
    cout << "\n------------\n";
    cout << rec(0, costs, days) << endl;
    cout << tab(costs, days) << endl;
    // cout << rec(str1, str2, str1.length(), str2.length()) << endl;
    // memset(dp, 0, sizeof(dp));
    // cout << tab(str1, str2, str1.length(), str2.length()) << endl;
    //------------------------------------------------------
    cout << endl;
    return 0;
}

/*
9
2 3 8 9 10 11 12 14 27
1 5 25
-------
*/
