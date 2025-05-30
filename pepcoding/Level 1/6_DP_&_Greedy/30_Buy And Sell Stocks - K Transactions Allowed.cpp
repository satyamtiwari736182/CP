// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are given a number k, representing the number of transactions allowed.
// 3. You are required to print the maximum profit you can make if you are allowed k transactions at-most.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include "../header.h"

void solve()
{
    int n, k;
    cin >> n;
    vi prices(n);
    rarr(prices, 0, n);
    cin >> k; // no. of transaction
    vvi dp_maxProfit(k + 1, vi(n));

    for (int transaction = 1; transaction <= k; transaction++)
        for (int day = 1; day < n; day++)
        {

            int maxProfit = dp_maxProfit[transaction][day - 1]; // current profit
            for (int prev_days = 0; prev_days < day; prev_days++)
            {
                int profit_till_trans_1 = dp_maxProfit[transaction - 1][prev_days];
                int profit_t_trans = prices[day] - prices[prev_days];

                if (profit_till_trans_1 + profit_t_trans > maxProfit)
                    maxProfit = profit_till_trans_1 + profit_t_trans;
            }

            dp_maxProfit[transaction][day] = maxProfit;
        }

    cout << endl;
    cout << dp_maxProfit[k][n - 1] << endl;
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
6
9
6
7
6
3
8
1
*/
