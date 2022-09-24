// 1. You are given two numbers A and B.
// 2. You are given two more numbers left and right, representing a range [left,right].
// 3. You have to set bits in B which are set in A lying in the above mentioned range.
// 4. Print the updated number B.



#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    int a, b, left, right;
    cin >> a >> b >> left >> right;
    cout << "\n========================================\n";
    bitset<32> val(a);
    cout << val << endl;
    int range = left - right + 1;
    int mask = (1 << range) - 1;
    mask <<= (right - 1);
    mask = a & mask;
    b = mask | b;
    val = b;
    cout << val << endl;

    cout << "\n========================================\n";
    return 0;
}


// 10
// 13
// 2
// 3