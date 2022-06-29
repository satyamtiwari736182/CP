// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the height of bars in a bar chart.
// 3. You are required to find and print the area of largest rectangle in the histogram.

// e.g.
// for the array [6 2 5 4 5 1 6] -> 12

#include "../header.h"

int *nse(int *arr, int n)
{
    stack<int> st;
    int *gre = new int[n + 1];
    gre[n] = -1;
    st.push(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() && arr[st.top()] >= arr[i])
            st.pop();
        if (st.empty())
            gre[i] = -1;
        else
            gre[i] = st.top();
        st.push(i);
    }
    return gre;
}

int *pse(int *arr, int n)
{
    stack<int> st;
    int *gre = new int[n + 1];
    gre[0] = -1;
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (st.size() && arr[st.top()] >= arr[i])
            st.pop();
        if (st.empty())
            gre[i] = -1;
        else
            gre[i] = st.top();
        st.push(i);
    }
    return gre;
}

int MAH(int *arr, int n)
{
    int *ns_idx = nse(arr, n);
    int *ps_idx = pse(arr, n);
    int area = 0;
    for (int i = 0; i <= n; i++)
    {
        int r = ns_idx[i];
        int l = ps_idx[i];
        int tempArea = arr[i] * (r - l - 1);
        if (tempArea > area)
            area = tempArea;
        cout << tempArea << " ";
    }
    cout << endl;
    return area;
}

void solve()
{
    int n;
    cin >> n;
    int arr[100];
    rarr(arr, 0, n);
    cout << MAH(arr, n - 1);
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

// 7
// 6
// 2
// 5
// 4
// 5
// 1
// 6