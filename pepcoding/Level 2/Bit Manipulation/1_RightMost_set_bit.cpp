// 1. You are given a number n.
// 2. You have to count the number of set bits in the given number.

// !Kernighans Algorithm

#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    bitset<10> val(n);

    cout << "\n========================================\n";
    int rightmost_set_bit = n & -n;
    cout << val << "\n"
         << rightmost_set_bit << endl;
    val = rightmost_set_bit;
    cout << val;

    cout << "\n========================================\n";
    return 0;
}

