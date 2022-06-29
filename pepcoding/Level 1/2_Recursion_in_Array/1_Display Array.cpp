// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to print the elements of array from beginning to end each in a separate line.
// 4. For the above purpose complete the body of displayArr function. Don't change the signature.

#include "../header.h"

void display(int *arr, int n)
{
    if (n < 0)
        return;
    display(arr, n - 1);
    cout << arr[n] << " ";
}

int main()
{
    cout << "hello!" << endl;
    int n, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    display(arr, n - 1);
    return 0;
}

// 5
// 3
// 1
// 0
// 7
// 5