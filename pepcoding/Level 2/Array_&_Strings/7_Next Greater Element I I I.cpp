// 1. Given a positive number 'n' in form of String.
// 2. Find the smallest number which has exactly the same digits existing in the number 'n' and is greater in value than 'n'.
// 3. If no such positive number exists, return -1 as string.

#include "../header.h"

void solve()
{
    string num;
    cin >> num;
    int i = num.length() - 2;

    // first dip
    while (i >= 0 && num[i] >= num[i + 1])
        i--;
    if (i == -1)
        return;
        
    int idx = 0, val = INF;
    for (int j = num.length() - 1; j > i; j--)
        if (num[j] > num[i] && num[j] - '0' < val)
            val = num[j] - '0', idx = j;

    swap(num[i], num[idx]);
    reverse(num.begin() + i + 1, num.end());

    cout << num << endl;
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*
6537421

*/

// 132