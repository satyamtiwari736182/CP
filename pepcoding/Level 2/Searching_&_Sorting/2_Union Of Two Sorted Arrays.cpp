// 1. Given two sorted arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.
// 2. Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

#include "../header.h"

vi solve(vi &arr1, vi &arr2)
{
    vi ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] == arr2[j])
        {
            ans.pb(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            ans.pb(arr1[i++]);

        else
            ans.pb(arr2[j++]);

        while (i < arr1.size() && arr1[i] == arr1[i - 1])
            i++;
        while (j < arr2.size() && arr2[j] == arr2[j - 1])
            j++;
    }

    while (i < arr1.size())
    {
        if (arr1[i] != arr1[i - 1])
            ans.pb(arr1[i]);
        i++;
    }
    while (j < arr2.size())
    {
        if (arr2[j] != arr2[j - 1])
            ans.pb(arr2[j]);
        j++;
    }

    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vi arr1, arr2;
        cin >> n;
        rvarr(arr1, 0, n);
        cin >> n;
        rvarr(arr2, 0, n);
        cout << "\n============================================\n";
        vi ans = solve(arr1, arr2);
        for (int val : ans)
            cout << val << " ";
        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 6
// 1 2 2 3 3 4
// 4
// 1 2 3 5

// 8
// 1 1 1 2 2 7 9 9
// 8
// 1 1 3 3 7 8 8 8