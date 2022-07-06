// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are given a number k.
// 4. You are required to find and print the k largest elements of array in increasing order.



#include "../header.h"

void solve()
{
    string str;
    priority_queue<int, vector<int>, greater<int>> pq;
    int arr[100], n, k;
    cin >> n;
    rarr(arr, 0, n);
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }

    cout << "\n****\n";
    while (!pq.empty())
        cout << pq.top() << " ", pq.pop();
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


// 13
// 12
// 62
// 22
// 15
// 37
// 99
// 11
// 37
// 98
// 67
// 31
// 84
// 99
// 4