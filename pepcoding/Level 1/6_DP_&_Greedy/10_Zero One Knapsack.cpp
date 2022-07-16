// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without
//      overflowing it's capacity.

// Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item
//                again and again.

#include "../header.h"
int knapSack(int capacity, int weight[], int profit[], int n)
{
    int obj, wt;
    vector<vi> dp(n + 1, vi(capacity + 1));

    for (obj = 0; obj <= n; obj++)
        for (wt = 0; wt <= capacity; wt++)
        {
            if (obj == 0 || wt == 0)
                dp[obj][wt] = 0;
            else if (weight[obj] <= wt)
                dp[obj][wt] = max(profit[obj] + dp[obj - 1][wt - weight[obj]], dp[obj - 1][wt]);
            else
                dp[obj][wt] = dp[obj - 1][wt];
        }
    cout << "********\n";
    pmatrix(dp, n + 1, capacity + 1);

    return dp[n][capacity];
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
    cout << "Maximum possible values: " << knapSack(W, wt, val, n);
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