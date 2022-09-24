// 1. You are given two numbers A and B.
// 2. You have to print the count of bits needed to be flipped to convert 'A' to 'B'.


#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    int a, b;
    cin >> a >> b;
    cout << "\n========================================\n";
    int bit_diff = a ^ b;
    int count = 0;
    while (bit_diff > 0)
    {
        count++;
        bit_diff -= (bit_diff & -bit_diff);
    }
    cout << "Num. of flip required: " << count;

    cout << "\n========================================\n";
    return 0;
}
