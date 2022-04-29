// Two players Alice and Bob are playing a game. They have a pile with n coins in it. They can pick either 1 or 2 coins in one turn. Alice goes first and they take alternate turns.The player who picks the last coin is the winner. Can you find out the winner.

#include "../header.h"

void solve()
{
    ll n;
    cin >> n;
    if (n % 3 == 0)// 3  ==> ( option_count + 1 )
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

// 10