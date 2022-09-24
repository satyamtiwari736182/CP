#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi prices(n + 1);
    rarr(prices, 0, n);

    int least_so_far = INT_MAX, overall_profit = 0, profit_if_sold_today = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < least_so_far)
            least_so_far = prices[i];
        profit_if_sold_today = prices[i] - least_so_far;
        if (profit_if_sold_today > overall_profit)
            overall_profit = profit_if_sold_today;
    }
    cout << overall_profit << endl;
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
-39957 -17136 35466 21820 -262711
*/

// #include "../header.h"

// void solve()
// {
//     int n, k;
//     cin >> n;
//     vi prices(n);
//     rarr(prices, 0, n);
//     cin >> k; // no. of transaction
//     vvi dp_maxProfit(k + 1, vi(n));

//     for (int transaction = 1; transaction <= k; transaction++)
//         for (int day = 1; day < n; day++)
//         {

//             int maxProfit = dp_maxProfit[transaction][day - 1]; // current profit
//             for (int prev_days = 0; prev_days < day; prev_days++)
//             {
//                 int profit_till_trans_1 = dp_maxProfit[transaction - 1][prev_days];
//                 int profit_t_trans = prices[day] - prices[prev_days];

//                 if (profit_till_trans_1 + profit_t_trans > maxProfit)
//                     maxProfit = profit_till_trans_1 + profit_t_trans;
//             }

//             dp_maxProfit[transaction][day] = maxProfit;
//         }

//     cout << endl;
//     cout << dp_maxProfit[k][n - 1] << endl;
// }

// int main()
// {
//     cout << "Hello world!\n";
//     int t = 1;
//     // cin>>t;
//     test(t)
//         solve();
//     return 0;
// }

// /*
// 6
// 9
// 6
// 7
// 6
// 3
// 8
// 1
// */