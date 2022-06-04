// 1. Assume you have an array of length 'n' initialized with all 0's and are given 'q' queries to update.
// 2. Each query is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
// 3. Return the modified array after all 'q' queries were executed.


#include "../header.h"

void solve()
{
    int n, q;
    cin >> n >> q;
    vi arr(n);
    test(q)
    {
        int l, r, val;
        cin >> l >> r >> val;
        arr[l] += val;
        arr[r + 1] += -val;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i], arr[i] = sum;
    parr(arr, n);
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

/*
12
4
2 6 4
0 5 3
1 4 -2
6 9 1
*/