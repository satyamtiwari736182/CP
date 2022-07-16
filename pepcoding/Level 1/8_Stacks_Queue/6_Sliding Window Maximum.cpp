// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the elements of array a.
// 3. You are given a number k, representing the size of window.
// 4. You are required to find and print the maximum element in every window of size k.

// e.g.
// for the array [2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6] and k = 4, the answer is [9 9 8 12 12 14 14 32 32 32 32 19 19 19]

#include "../header.h"

int *nge(int *arr, int n)
{
    stack<int> st;
    int *gre = new int[n];
    gre[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() && arr[i] >= arr[st.top()])
            st.pop();
        if (st.empty())
            gre[i] = n;
        else
            gre[i] = st.top();
        st.push(i);
    }
    return gre;
}

void solve()
{
    int n, k;
    cin >> n;
    int arr[100];
    rarr(arr, 0, n);
    cin >> k;
    cout << "\n****************\n";
    int *nge_idx = nge(arr, n);

    // for (int i = 0; i < n; i++)
    //     cout << ns_idx[i] << " ";
    int j = 0;
    for (int i = 0; i <= n - k; i++)
    {
        // enter the loop to find the maximum of window starting at i
        if (j < i)
            j = i;
        while (nge_idx[j] < i + k)//checking the idx j lies within the window
            j = nge_idx[j];
        cout << arr[j] << " ";
    }
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}
/*
7
6 2 5 4 5 1 6
*/

// 17
// 2
// 9
// 3
// 8
// 1
// 7
// 12
// 6
// 14
// 4
// 32
// 0
// 7
// 19
// 8
// 12
// 6
// 4