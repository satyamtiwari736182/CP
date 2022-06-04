// 1. Given an integer array of size 'n'.
// 2. Find all elements that appear more than n / 3 times and return it in an arraylist.
// 3. Note : solve the problem in linear time and in O(1) space.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n), ans(n);
    rarr(arr, 0, n);
    int val1 = INF, val2 = INF, cnt2 = 0, cnt1 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == val1)
            cnt1++;
        else if (arr[i] == val2)
            cnt2++;
        else
        {
            if (cnt1 == 0)
                val1 = arr[i], cnt1++;
            else if (cnt2 == 0)
                val2 = arr[i], cnt2++;
            else
                cnt1--, cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;

    for (int ele : arr)
    {
        if (val1 == ele)
            cnt1++;
        if (val2 == ele)
            cnt2++;
    }

    // vi ans;
    if (cnt1 >= (n + 1) / 3)
        cout << val1 << " ";
    if (cnt2 >= (n + 1) / 3)
        cout << val2 << " ";
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
7
1 2 1 3 2 2 1
*/

/*
3
3 2 3
*/