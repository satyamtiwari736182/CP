// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. You are required to find the intersection of a1 and a2. To get an idea check the example below:

// if a1 -> 1 1 2 2 2 3 5
// and a2 -> 1 1 1 2 2 4 5
// intersection is -> 1 1 2 2 5

// Note -> Don't assume the arrays to be sorted. Check out the question video.

#include "../header.h"

void solve()
{
    string str;
    unordered_map<int, int> hashmap;
    int arr1[100], arr2[100], n1, n2;
    cin >> n1;
    rarr(arr1, 0, n1);
    cin >> n2;
    rarr(arr2, 0, n2);

    for (int i = 0; i < n1; i++)
        hashmap[arr1[i]]++;

    for (int i = 0; i < n2; i++)
        if (hashmap[arr2[i]])
            cout << arr2[i] << " ", hashmap[arr2[i]]--;
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

// 7
// 1
// 1
// 2
// 2
// 2
// 3
// 5
// 7
// 1
// 1
// 1
// 2
// 2
// 4
// 5