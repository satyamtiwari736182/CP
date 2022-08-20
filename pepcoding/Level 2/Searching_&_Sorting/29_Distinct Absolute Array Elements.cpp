// Given a sorted array of size N. Count the number of distinct absolute values present in the array.

#include "../header.h"

void solve(vi &arr)
{
    int ileft = INT_MIN, jright = INT_MAX, cnt = 0, i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        if (abs(arr[i]) == abs(arr[j]))
        {
            if (ileft != arr[i] && jright != arr[j])
                cnt++;
            ileft = arr[i], jright = arr[j], i++, j--;
        }

        else if (abs(arr[i]) < abs(arr[j]))
        {
            if (jright != arr[j])
                cnt++;
            jright = arr[j];
            j--;
        }

        else if (abs(arr[i]) > abs(arr[j]))
        {
            if (ileft != arr[i])
                cnt++;
            ileft = arr[i];
            i++;
        }
    }

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

/*
6
-3 -2 0 3 4 5
*/