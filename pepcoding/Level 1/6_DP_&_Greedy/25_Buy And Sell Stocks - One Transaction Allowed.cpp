// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed a single transaction.

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

// 9
// 11
// 6
// 7
// 19
// 4
// 1
// 6
// 18
// 4