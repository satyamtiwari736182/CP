#include "header.h"

void calcAllSubsetSub(vi &arr, vi &x, int left, int right)
{
    int n = right - left;
    for (int i = 0; i < (1 << n); i++) // all the possible combination
    // 2^n
    {
        ll sum = 0;
        for (int j = 0; j < n; j++) // number of element used from array
            if (i & (1 << j))
                sum += arr[j + left];
        x[i] = sum;
    }
}

ll solveSubsetSum(vi &arr, int sum)
{
    int n = arr.size();
    vi x(1 << n / 2);
    vi y(1 << n - n / 2);

    calcAllSubsetSub(arr, x, 0, n / 2); // all possible subSetSum of first half
    calcAllSubsetSub(arr, y, n / 2, n); // all possible subSetSum of first half

    sort(all(y));
    int res = 0;
    for (int val : x)
        if (val <= sum)
        {
            int idx = lower_bound(all(y), sum - val) - begin(y);
            if (idx == y.size() || y[idx] != sum - val)
                idx--;
            res = max(res, y[idx] + val);
        }

    parr(x, x.size());
    cout << endl;
    parr(y, y.size());
    cout << endl;
    return res;
}

void solve()
{
    int n, sm = 0;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> sm;
    // ---------------------------------
    cout << solveSubsetSum(arr, sm);
    // ---------------------------------
}

int main()
{
    cout << "hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
6
3 9 7 3 5 2
23
*/