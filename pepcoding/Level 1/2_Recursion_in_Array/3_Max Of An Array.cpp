// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are required to find the maximum of input.
// 4. For the purpose complete the body of maxOfArray function. Don't change the signature.

#include "../header.h"

int findMax(int *arr, int n)
{
    if (n < 0)
        return -1;
    int b = arr[n];
    int a = findMax(arr, n - 1);
    return a > b ? a : b;
}

int main()
{
    cout << "hello!" << endl;
    int n, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    cout << findMax(arr, n - 1);
    return 0;
}

// 6
// 15
// 30
// 40
// 4
// 11
// 9