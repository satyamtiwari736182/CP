// 1. You are given an array of numbers.
// 2. All numbers occur twice in the array except one.
// 3. You have to find that number by traversing only once in the array and without using any extra 
//      space.

#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);

    cout << "\n========================================\n";
    int single_ele = 0;
    for (int i = 0; i < n; i++)
        single_ele ^= arr[i];
    cout << single_ele;
    cout << "\n========================================\n";
    return 0;
}

// 7
// 2 3 2 3 5 6 6
