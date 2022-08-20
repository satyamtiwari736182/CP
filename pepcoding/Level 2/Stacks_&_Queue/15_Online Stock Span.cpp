// 1: Complete the next function in class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.
// 2: The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

// For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

#include "../header.h"

struct Pair
{
    int price;
    int index;
};

class stockSpanner
{
public:
    stack<Pair> stk;
    int tim = 0;
    stockSpanner()
    {
        stk.push({1000000, -1});
    }

    int next(int price)
    {
        Pair newStock = {price, tim++};
        while (stk.top().price <= newStock.price)
            stk.pop();
        int ans = newStock.index - stk.top().index;
        stk.push(newStock);
        return ans;
    }
};

void solve()
{
    stockSpanner stock;
    while (1)
    {
        int price;
        cin >> price;
        cout << "Current stocks span: "
             << stock.next(price) << endl;
    }
    cout << "\n------------\n";
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

// 100
// 80
// 60
// 70
// 60
// 75
// 85