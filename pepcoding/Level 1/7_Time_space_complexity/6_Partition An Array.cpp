// 1. You are given an array(arr) of integers and a pivot.
// 2. You have to re-arrange the given array in such a way that all elements smaller or equal to pivot lie on the left side of pivot and all elements greater than pivot lie on its right side.
// 3. You have to achieve this in linear time.
#include "../header.h"

void solve()
{
    int n, pivot, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    cin >> pivot;
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] > pivot)
            j++;
        else
            swap(arr[i], arr[j]), i++, j++;
    }

    cout << "\n*******\n";
    parr(arr, n);
}

int main()
{
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
5
7
-2
4
1
3
3
*/