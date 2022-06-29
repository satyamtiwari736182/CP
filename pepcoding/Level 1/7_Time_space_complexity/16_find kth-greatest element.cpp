
#include "../header.h"

int partition(vector<int> &arr, int left, int right, int pivot)
{
    int i = left, j = left;
    while (j <= right)
    {
        if (arr[j] < pivot)
            j++;
        else
            swap(arr[i], arr[j]), i++, j++;
    }
    return i - 1;
}

int quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left > right)
        return -1;
    int pivot = arr[right];
    int pivot_idx = partition(arr, left, right, pivot);
    if (pivot_idx == k)
        return arr[k];
    else if (k > pivot_idx)
        return quickSelect(arr, pivot_idx + 1, right, k);
    else
        return quickSelect(arr, left, pivot_idx - 1, k);
}

int findKthLargest(vector<int> &nums, int k)
{
    int val = quickSelect(nums, 0, nums.size() - 1, k - 1);
    return val;
}
void solve()
{
    int n, k;
    vi arr(100);
    cin >> n;
    rarr(arr, 0, n);
    cin >> k;
    int val = findKthLargest(arr, k);
    cout << "\n" << val << endl;
    // parr(arr, n);
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
5
7 -2 4 1 3
3

6
3 2 1 5 6 4
2
*/

