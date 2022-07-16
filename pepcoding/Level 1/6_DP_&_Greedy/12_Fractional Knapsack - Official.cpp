
// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without overflowing it's capacity.
// Note1 -> Items can be added to the bag even partially. But you are not allowed to put same items again and again to the bag.

#include "../header.h"

int knapSack(int capacity, int weight[], int profit[], int n)
{
    vii object(n);

    for (int i = 1; i <= n; i++)
        object[i - 1] = {weight[i], profit[i]};

    sort(all(object), [&](const pi a, const pi b)
         { return b.se < a.se; });

    int maxProfit = 0;
    for (auto pr : object)
    {
        if (capacity >= pr.fs)
            maxProfit += pr.se, capacity -= pr.fs;
        else if (capacity > 0)
            maxProfit += pr.se * capacity / pr.fs, capacity -= capacity;
    }

    return maxProfit;
}

void solve()
{

    int n, W;
    cin >> n;
    int *val = new int[n + 1];
    int *wt = new int[n];
    rarr(val, 1, n + 1);
    rarr(wt, 1, n + 1);

    cin >> W;
    cout << "\nMaximum possible values: " << knapSack(W, wt, val, n);
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
15 14 10 45 30
2 5 1 3 4
7
*/

// 10
// 33 14 50 9 8 11 6 40 2 15
// 7 2 5 9 3 2 1 10 3 3
// 5