#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    // int n;
    // cin >> n;
    // 01101110
    int n = 0b10011101;
    cout << "\n========================================\n";
    int even_mask = 0xAAAAAAAA;
    int odd_mask = 0x55555555;
    int even_bits = n & even_mask;
    int odd_bits = n & odd_mask;
    int swaped_bits = (even_bits >> 1) | (odd_bits << 1);
    bitset<8> val(n);
    cout << val << endl;
    val = swaped_bits;
    cout << val << endl;
    cout << swaped_bits << endl;

    cout << "\n========================================\n";
    val = even_bits;
    cout << val << endl;
    val = odd_bits;
    cout << val;
    return 0;
}
