// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to print the elements of array from end to beginning each in a separate line.
// 4. For the above purpose complete the body of displayArrReverse function. Don't change the signature.

#include "../header.h"

void displayR(int *arr, int n)
{
    if (n < 0)
        return;
    cout << arr[n] << " ";
    displayR(arr, n - 1);
}

int main()
{
    cout << "hello!" << endl;
    int n, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    displayR(arr, n - 1);
    return 0;
}

// 5
// 3
// 1
// 0
// 7
// 5