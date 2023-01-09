// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the combinations of the n coins (same coin can be used
//      again any number of times) using which the amount "amt" can be paid.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
//! Combination method
void coinChange(int cc, vi &coins, int amtsf, int tar, string asf)
{
    if (cc == coins.size())
    {
        if (amtsf == tar)
            cout << asf << endl;
        return;
    }

    for (int j = tar / coins[cc]; j >= 1; j--)
    {
        string part = "";
        for (int k = 0; k < j; k++)
            part += to_string(coins[cc]) + "-";
        coinChange(cc + 1, coins, amtsf + coins[cc] * j, tar, asf + part);
    }

    coinChange(cc + 1, coins, amtsf, tar, asf);
}
void solve()
{
    int n, tar;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> tar;
    cout << endl;
    coinChange(0, arr, 0, tar, "");
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}
/*
5
2
3
5
6
7
12
*/