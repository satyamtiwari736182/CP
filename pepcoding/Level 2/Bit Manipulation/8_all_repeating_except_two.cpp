// 1. You are given an array of numbers.
// 2. You have to find 2 non-repeating numbers in an array.
// 3. All repeating numbers are repeating even number of times.

#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);

    cout << "\n========================================\n";
    int xor_two = 0;
    for (int i = 0; i < n; i++)
        xor_two ^= arr[i];

    int rmbit = xor_two & -xor_two;
    int rmbit_grp_xor = 0;
    int non_rmbit_grp_xor = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rmbit)
            rmbit_grp_xor ^= arr[i];
        else
            non_rmbit_grp_xor ^= arr[i];
    }
    int a = xor_two ^ rmbit_grp_xor;
    int b = xor_two ^ non_rmbit_grp_xor;
    cout << a << "\t" << b;
    cout << "\n========================================\n";
    return 0;
}

// 6
// 2 2 3 5 6 6
