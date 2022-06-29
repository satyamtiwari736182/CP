// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number x.
// 4. You are required to find the last index at which x occurs in array a.
// 5. If x exists in array, print the last index where it is found otherwise print -1.

#include "../header.h"

int lastIndex(int *arr, int n, int val)
{

    if (n < 0)
        return -1;
    if (arr[n] == val)
        return n + 1;
    int idx = lastIndex(arr, n - 1, val);
    return idx;
}

int main()
{
    cout << "hello!" << endl;
    int n, arr[100], val;
    cin >> n;
    rarr(arr, 0, n);
    cin >> val;
    cout << lastIndex(arr, n - 1, val);
    return 0;
}

// 6
// 15
// 11
// 40
// 4
// 4
// 9
// 4