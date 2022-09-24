#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    int msk = 0b010101010101010101;
    cout << "\n========================================\n";
    int mask = 0x55555555;
    bitset<32> val(mask);
    // cout << val;
    if (n && ((n & (n - 1)) == 0) && (n & mask))
        cout << "Is a power of 4" << endl;
    else
        cout << "Is NOT a power of 4" << endl;

    cout << "\n========================================\n";
    return 0;
}
