// 1. Given an array of integers. Find the Inversion Count in the array.
// 2. For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
// 3. Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

#include "../header.h"
int count_inv = 0;
vi mergeSortedArray(vi leftarr, vi rightarr)
{
    vi mergedarr;
    int i = 0, j = 0;
    while (i < leftarr.size() && j < rightarr.size())
    {
        if (leftarr[i] <= rightarr[j])
            mergedarr.pb(leftarr[i++]);
        else
        {
            count_inv += leftarr.size() - i;
            mergedarr.pb(rightarr[j++]);
        }
    }

    while (i < leftarr.size())
        mergedarr.pb(leftarr[i++]);
    while (j < rightarr.size())
        mergedarr.pb(rightarr[j++]);

    return mergedarr;
}

vi mergeSort(vi &arr, int left, int right)
{
    if (left == right)
        return {arr[left]};

    int mid = (left + right) / 2;
    vi leftarr = mergeSort(arr, left, mid);
    vi rightarr = mergeSort(arr, mid + 1, right);

    vi mergedarr = mergeSortedArray(leftarr, rightarr);

    return mergedarr;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";

        vi ans = mergeSort(arr, 0, n - 1);
        // for (int val : ans)
        //     cout << val << " ";
        cout << "\n"
             << count_inv << endl;

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 5
// 2 4 1 3 5

// 7
// 8 5 3 4 1 6 2