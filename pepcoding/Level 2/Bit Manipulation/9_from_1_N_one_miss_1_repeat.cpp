// 1. You are given an array of length n containing numbers from 1 to n.
// 2. One number is present twice in array and one is missing.
// 3. You have to find these two numbers.

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
        xor_two = xor_two ^ arr[i] ^ (i + 1);

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
    
    //--------------------------------------------
    int a = xor_two ^ rmbit_grp_xor;
    int b = xor_two ^ non_rmbit_grp_xor;

    if (find(arr, arr + n, b) == (arr + n))
        a = xor_two ^ b;
    else
    {
        b = a;
        a = xor_two ^ b;
    }
    //--------------------------------------------

    cout << a << "\t" << b << endl;

    cout << "\n========================================\n";
    return 0;
}

// 6
// 2 1 3 4 4 5
