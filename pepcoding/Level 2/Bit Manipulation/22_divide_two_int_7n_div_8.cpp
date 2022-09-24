#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    cout << "\n========================================\n";
    //! Solve 7n/8
    //? hints: (8n-n)/8
    //* using >> or <<
    int val = (n << 3) - n;
    int ans = val >> 3;
    cout << ans;

    cout << "\n========================================\n";
    return 0;
}
