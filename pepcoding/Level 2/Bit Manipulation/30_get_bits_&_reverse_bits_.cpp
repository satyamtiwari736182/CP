// 1. You are given a number.
// 2. You have to print its binary representation.
// 3. You also have to reverse the bits of n and print the number obtained after reversing the bits.

#include "../header.h"

int sol(int n)
{
    bool flag = false;
    int rev = 0;
    int j = 0;

    for (int i = 31; i >= 0; i--)
    {
        int mask = (1 << i);

        if (flag)
        {
            if ((n & mask) != 0)
            {
                cout << 1;
                int smask = (1 << j);
                rev |= smask;
            }
            else
                cout << 0;
            j++;
        }

        else if ((n & mask) != 0)
        {
            flag = true;
            cout << 1;
            int smask = (1 << j);
            rev |= smask;
            j++;
        }
    }

    return rev;
}
int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;

    cout << "\n========================================\n";
    bitset<32> val(n);
    cout << val << endl;

    int rev = sol(n);
    bitset<32> val2(rev);
    cout << endl
         << rev << endl
         << val2;
    cout << "\n========================================\n";
    return 0;
}
