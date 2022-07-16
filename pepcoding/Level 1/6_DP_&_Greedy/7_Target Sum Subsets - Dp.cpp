// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. You are required to calculate and print true or false, if there is a subset the elements of which add
//      up to "tar" or not.

#include "../header.h"

void solve()
{
    int n, tar;
    bool dp[N][N];
    cin >> n;
    int *arr = new int[n + 1];
    rarr(arr, 1, n + 1);
    cin >> tar;
    Fill(dp, 0);

    for (int coin = 0; coin <= n; coin++)    // values available
        for (int amt = 0; amt <= tar; amt++) // target
        {
            if (coin == 0 && amt == 0)
                dp[coin][amt] = 1;
            else if (coin == 0)
                dp[coin][amt] = 0;
            else if (amt == 0)
                dp[coin][amt] = 1;
            else
            {
                dp[coin][amt] = dp[coin - 1][amt]; // not including
                int val = arr[coin];
                if ((amt >= val))
                    dp[coin][amt] |= dp[coin - 1][amt - val]; // including val and checking for remaining amt.
            }
        }

    pmatrix(dp, n + 1, tar + 1);
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
5
4
2
7
1
3
10
*/

// 5
// 4
// 2
// 7
// 1
// 3
// 10