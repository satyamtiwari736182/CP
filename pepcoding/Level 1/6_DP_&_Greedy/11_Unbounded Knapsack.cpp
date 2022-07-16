// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without
//     overflowing it's capacity.
// Note -> Each item can be taken any number of times. You are allowed to put the same item again
//                   and again.

#include "../header.h"
int knapSack(int capacity, int weight[], int profit[], int n)
{
    int obj, wt;
    vi dp(capacity + 1);

    for (wt = 1; wt <= capacity; wt++)
        for (obj = 0; obj <= n; obj++)
            if (wt >= weight[obj])
                dp[wt] = max(dp[wt], profit[obj] + dp[wt - weight[obj]]);

    cout << "********\n";
    parr(dp, capacity + 1);
    return dp[capacity];
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