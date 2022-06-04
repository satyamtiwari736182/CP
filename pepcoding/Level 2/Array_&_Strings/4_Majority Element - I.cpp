// 1. Give an array of size 'n'.
// 2. Find Majority element and print it(if exist), otherwise print "No Majority Element exist".
// 3. Majority element-> if frequency of an element is more than n/2, then that element is majority element.
// 3. Note : solve the problem in linear time and in O(1) space.


#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n), ans(n);
    rarr(arr, 0, n);
    int val = INF, cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt == 0)
            val = arr[i], cnt++;
        else if (arr[i] == val)
            cnt++;
        else
            cnt--;
    }
    cnt = 0;
    for (int ele : arr)
        if (val == ele)
            cnt++;
    cout << (cnt == (n + 1) / 2 ? val : -1);
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
2 2 1 1 1 2 2
*/