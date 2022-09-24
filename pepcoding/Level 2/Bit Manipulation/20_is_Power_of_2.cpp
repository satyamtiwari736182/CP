#include "../header.h"
int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    cout << "\n========================================\n";
    if ((n & (n - 1)) == 0)
        cout << "Is a power of two" << endl;
    else
        cout << "Is NOT a power of two" << endl;

    cout << "\n========================================\n";
    return 0;
}
