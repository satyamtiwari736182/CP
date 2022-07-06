// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. You are required to print all elements of a2 which are also present in a1 (in order of their occurence in a2). Make sure to not print duplicates (a2 may have same value present many times).

#include "../header.h"

void solve()
{
    string str;
    unordered_set<int> hashset;
    int arr1[100], arr2[100], n1, n2;
    cin >> n1;
    rarr(arr1, 0, n1);
    cin >> n2;
    rarr(arr2, 0, n2);

    for (int i = 0; i < n1; i++)
        hashset.insert(arr1[i]);

    for (int i = 0; i < n2; i++)
        if (hashset.count(arr2[i]) == 1)
            cout << arr2[i] << " ", hashset.erase(arr2[i]);
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

// 9
// 5
// 5
// 9
// 8
// 5
// 5
// 8
// 0
// 3
// 18
// 9
// 7
// 1
// 0
// 3
// 6
// 5
// 9
// 1
// 1
// 8
// 0
// 2
// 4
// 2
// 9
// 1
// 5