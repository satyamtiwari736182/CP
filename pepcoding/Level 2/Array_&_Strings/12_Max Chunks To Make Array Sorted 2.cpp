// 1. Given an array arr of integers (not necessarily distinct).
// 2. We split the array into some number of "chunks" (partitions), and individually sort each chunk.  
// 3. After concatenating them, the result equals the sorted array.
// 4. What is the most number of chunks we could have made?

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n), rmin(n + 1, INF);

    rarr(arr, 0, n);
    for (int i = arr.size() - 1; i >= 0; i--)
        rmin[i] = min(rmin[i + 1], arr[i]);

    int leftMax = -INF, i = 0, chunk_cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        leftMax = max(leftMax, arr[i]);
        if (leftMax <= rmin[i + 1])
            chunk_cnt++;
    }

    // parr(rmin, n);
    cout << "\n"
         << chunk_cnt << endl;
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
8
4 3 6 5 7 12 11 10

*/
