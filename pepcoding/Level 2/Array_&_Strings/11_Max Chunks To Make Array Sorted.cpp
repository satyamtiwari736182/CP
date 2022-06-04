// 1. Given an array arr that is a permutation of [0, 1, ..., arr.length - 1].
// 2. We split the array into some number of "chunks" (partitions), and individually sort each chunk. 
// 3. Shuffling of chunk is not allowed.
// 4. After concatenating them, the result equals the sorted array.
// 5. What is the most number of chunks we could have made?

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    int leftMax = arr[0], i = 0, chunk_cnt = 0;

    while (i < n)
    {
        while (i < leftMax)
            leftMax = max(leftMax, arr[i]), i++;

        chunk_cnt++;
        i++;
        leftMax = arr[i];
    }
    cout << chunk_cnt << endl;
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
6
2 0 1 3 5 4
*/
