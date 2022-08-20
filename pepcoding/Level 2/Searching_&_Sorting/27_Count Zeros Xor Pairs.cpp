// 1. Given an array A[] of size N.
// 2. Find the number of pairs (i, j) such that A[i] XOR A[j] = 0, and 1 <= i < j <= N.

#include "../header.h"

void solve(vi &arr)
{
    map<int, int> freq;
    for (int val : arr)
        freq[val]++;

    int cnt_pair = 0;
    for (pi pr : freq)
    {
        int cnt = pr.se - 1;
        cnt_pair += cnt * (cnt + 1) / 2;
    }
    cout << endl;
    cout << cnt_pair;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";

        solve(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 6
// 1 3 1 3 1 1