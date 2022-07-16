// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed infinite transactions.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy)

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi prices(n + 1);
    rarr(prices, 0, n);
    int buying_date = 0, selling_date = 0, profit = 0;

    for (int day = 1; day < prices.size(); day++)
    {
        if (prices[day] >= prices[day - 1])
            selling_date++;
        else
            profit += prices[selling_date] - prices[buying_date],
                buying_date = selling_date = day;
    }
    cout << profit << endl;
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