// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the prices of a share on n days.
// 3. You are required to find the stock span for n days.
// 4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.

// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// span for 2 is 1
// span for 5 is 2
// span for 9 is 3
// span for 3 is 1
// span for 1 is 1
// span for 12 is 6
// span for 6 is 1
// span for 8 is 2
// span for 7 is 1

#include "../header.h"

void stockSpan(int *arr, int n)
{
    stack<int> st;
    int nge[100];
    nge[0] = 1;
    st.push(0);

    for (int i = 1; i <= n; i++)
    {
        while (st.size() && arr[st.top()] < arr[i])
            st.pop();
        if (st.empty())
            nge[i] = i + 1;
        else
            nge[i] = i - st.top();
        st.push(i);
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
    stockSpan(arr, n - 1);
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
9
2 5 9 3 1 12 6 8 7
*/
