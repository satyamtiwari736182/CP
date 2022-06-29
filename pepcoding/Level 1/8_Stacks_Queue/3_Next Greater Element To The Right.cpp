// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to "next greater element on the right" for all elements of array
// 4. Input and output is handled for you.

#include "../header.h"

void NGE(int *arr, int n)
{
    stack<int> st;
    int nge[100];
    nge[n] = -1;
    st.push(arr[n]);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() && st.top() < arr[i])
            st.pop();
        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();
        st.push(arr[i]);
    }
    for (int i = 0; i <= n; i++)
        cout << nge[i] << " ";
}

void solve()
{
    int n;
    cin >> n;
    int arr[100];
    rarr(arr, 0, n);
    NGE(arr, n - 1);
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
5
5 3 8 -2 7

*/