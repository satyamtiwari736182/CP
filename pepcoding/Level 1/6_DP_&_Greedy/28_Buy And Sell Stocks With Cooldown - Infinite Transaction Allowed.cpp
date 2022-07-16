// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
// i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include "../header.h"

void solve()
{
    int n, fees;
    cin >> n;
    vi prices(n);
    rarr(prices, 0, n);
    // cin >> fees;
    int bought_sate_profit = -prices[0], sell_state_profit = 0, cool_down_state_profit = 0;

    for (int day = 1; day < n; day++)
    {
        int nbsp = 0, nssp = 0, ncdsp = 0;

        if (cool_down_state_profit - prices[day] > bought_sate_profit)
            nbsp = cool_down_state_profit - prices[day];
        else
            nbsp = bought_sate_profit;

        if (bought_sate_profit + prices[day] > sell_state_profit)
            nssp = bought_sate_profit + prices[day];
        else
            nssp = sell_state_profit;

        if (sell_state_profit > cool_down_state_profit)
            ncdsp = sell_state_profit;
        else
            ncdsp = cool_down_state_profit;

        bought_sate_profit = nbsp;
        sell_state_profit = nssp;
        cool_down_state_profit = ncdsp;
    }

    cout << endl;
    cout << sell_state_profit << endl;
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
12
10
15
17
20
16
18
22
20
22
20
23
25
*/