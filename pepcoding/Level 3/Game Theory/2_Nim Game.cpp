// Two players Alice and Bob are playing a game. They have n piles. ith pile conatins arr[i] no. of coins. In each move a player can choose a pile and remove as many coins as he wants (minimum 1 coin). The player who removes the last set of coins from table will win. Alice goes first.

#include "../header.h"

void solve()
{
    ll nimSum = 0;
    int n;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);

    for (int i = 0; i < n; i++)
        nimSum ^= arr[i];

    if (nimSum == 0)
        cout << "BOB\n";
    else
        cout << "ALICE\n";
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

// 3
// 1 2 3