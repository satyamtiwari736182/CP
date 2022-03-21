#include "../header.h"

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);

    cout << "\n========================================\n";
    int all_pair_xor = 0;
    REP(0, n - 1)
    all_pair_xor ^= arr[i];
    all_pair_xor *= 2;
    cout << all_pair_xor;
    cout << "\n========================================\n";
    return 0;
}
// 4
// 1 2 3 4