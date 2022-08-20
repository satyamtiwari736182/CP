// Given an array ht representing heights of buildings. You have to count the buildings which will see the sunrise (Assume : Sun rise on the side of array starting point).

#include "../header.h"

void solve(vi &arr)
{
    int leftMax = arr[0], cnt = 1;
    for (int i = 1; i < arr.size(); ++i)
        if (leftMax < arr[i])
            leftMax = arr[i], cnt++;
    cout << cnt << endl;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";
        solve(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

// 5
// 7 4 8 2 9