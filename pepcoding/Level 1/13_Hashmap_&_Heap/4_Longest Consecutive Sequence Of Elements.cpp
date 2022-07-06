// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to print the longest sequence of consecutive elements in the array (ignoring duplicates).

// Note -> In case there are two sequences of equal length (and they are also the longest), then print the one for which the starting point of which occurs first in the array.

#include "../header.h"

void solve()
{
    string str;
    unordered_map<int, int> hashmap;
    int arr[100], n;
    cin >> n;
    rarr(arr, 0, n);

    for (int i = 0; i < n; i++)
        hashmap[arr[i]] = true;

    for (int i = 0; i < n; i++)
        if (hashmap[arr[i] - 1])
            hashmap[arr[i]] = false;

    int startPoint = 0, cnt = 0;

    for (int i = 0; i < n; i++)
        if (hashmap[arr[i]])
        {
            int strt = arr[i];
            int tcnt = 1;
            while (hashmap.count(strt + tcnt))
                tcnt++;
            if (tcnt > cnt)
                startPoint = strt, cnt = tcnt;
        }
    cout << "\n****\n";
    for (int i = 0; i < cnt; i++)
        cout << (startPoint + i) << " ";
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

// 17
// 12
// 5
// 1
// 2
// 10
// 2
// 13
// 7
// 11
// 8
// 9
// 11
// 8
// 9
// 5
// 6
// 11