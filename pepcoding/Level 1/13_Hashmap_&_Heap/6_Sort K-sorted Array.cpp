// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. The array is nearly sorted. Every element is at-max displaced k spots left or right to it's position in the sorted array. Hence it is being called k-sorted array.
// 4. You are required to sort and print the sorted array.

// Note -> You can use at-max k extra space and nlogk time complexity.

#include "../header.h"

void solve()
{
    string str;
    priority_queue<int, vector<int>, greater<int>> pq;
    int arr[100], n, k;
    cin >> n;
    rarr(arr, 0, n);
    cin >> k;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            arr[idx] = pq.top(), idx++, pq.pop();
    }

    cout << "\n****\n";
    while (!pq.empty())
        arr[idx] = pq.top(), idx++, pq.pop();

    parr(arr, n);
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
// 3
// 2
// 4
// 1
// 6
// 5
// 7
// 9
// 8
// 3