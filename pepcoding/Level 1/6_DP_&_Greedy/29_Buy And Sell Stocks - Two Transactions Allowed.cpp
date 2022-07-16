// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include "../header.h"

void solve()
{
    int n, fees;
    cin >> n;
    vi prices(n);
    rarr(prices, 0, n);
    // cin >> fees;

    int maxProfit_if_sold_today = 0, leastPrice_so_far = prices[0];
    vi dp_maxProfitIfSold_until_today(n);
    for (int day = 1; day < n; day++)
    {
        if (prices[day] < leastPrice_so_far)
            leastPrice_so_far = prices[day];

        maxProfit_if_sold_today = prices[day] - leastPrice_so_far;

        if (maxProfit_if_sold_today > dp_maxProfitIfSold_until_today[day - 1])
            dp_maxProfitIfSold_until_today[day] = maxProfit_if_sold_today;
        else
            dp_maxProfitIfSold_until_today[day] = dp_maxProfitIfSold_until_today[day - 1];
    }

    //*********************************

    int maxProfit_if_bought_today = 0, maxPrice_in_future = prices[n - 1];
    vi dp_maxProfitIfSold_in_future(n);
    for (int day = n - 2; day >= 0; day--)
    {
        if (prices[day] > maxPrice_in_future)
            maxPrice_in_future = prices[day];

        maxProfit_if_bought_today = maxPrice_in_future - prices[day];

        if (maxProfit_if_bought_today > dp_maxProfitIfSold_in_future[day + 1])
            dp_maxProfitIfSold_in_future[day] = maxProfit_if_bought_today;
        else
            dp_maxProfitIfSold_in_future[day] = dp_maxProfitIfSold_in_future[day + 1];
    }
    //*******************

    int maxProfit = 0;
    for (int day = 0; day < n; day++)
        maxProfit = max(maxProfit, dp_maxProfitIfSold_until_today[day] + dp_maxProfitIfSold_in_future[day]);

    cout << endl;
    cout << maxProfit << endl;
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
9
11
6
7
19
4
1
6
18
4
*/