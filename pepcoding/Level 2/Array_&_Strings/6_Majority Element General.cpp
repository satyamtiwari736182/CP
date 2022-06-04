// 1. Given an array of size 'N' and an element K.
// 2. Task is to find all elements that appears more than N/K times in array.
// 3. Return these elements in an ArrayList in sorted order.


#include "../header.h"

void solve()
{
    int n, k;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> k;
    
    map<int, int> hashmap;
    for (int ele : arr)
        hashmap[ele]++;

    for (pi pr : hashmap)
        if (pr.se >= (n + 1) / k)
            cout << pr.fs << " ";
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
3 1 2 2 1 2 3 3
4
*/

/*

10
1 2 3 1 3 2 5 1 4 3
5

*/