// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the number of combinations of the n coins using which the
//      amount "amt" can be paid.

// Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be
//                   used for many installments in payment of "amt"
// Note2 -> You are required to find the count of combinations and not permutations i.e.
//                   2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same
//                   combination. You should treat them as 1 and not 3.

#include "../header.h"

void solve()
{
    int n, dp[N] = {0}, tar;
    cin >> n;
    int *arr = new int[n + 1];
    rarr(arr, 1, n + 1);
    cin >> tar;
    dp[0] = 1;
    for (int coin = 1; coin <= n; coin++)
        for (int amt = arr[coin]; amt <= tar; amt++)
        {
            int val = arr[coin];
            if (dp[amt - val])
                dp[amt] += dp[amt - val];
        }

    parr(dp, tar + 1);
    cout << endl;
    cout << dp[tar];
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
4
2
3
5
6
7
*/