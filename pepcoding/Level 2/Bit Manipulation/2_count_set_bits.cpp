// 1. You are given a number n.
// 2. You have to count the number of set bits in the given number.

// !Kernighans Algorithm

#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;
    int n, count = 0;
    cin >> n;
    bitset<10> val(n);

    cout << "\n========================================\n";
    while (n > 0)
    {
        count++;
        n -= n & -n;
    }
    cout << val << "\n"
         << count << endl;

    cout << "\n========================================\n";
    return 0;
}
