// Two players Alice and Bob are playing a game. They have a pile with n coins in it.
// They can pick only allowed numbers of coins at a time given in an array picks.
// Alice goes first and they take alternate turns.
// The player who picks the last coin is the winner. Can you find out the winner.

//!===== General form of one two three picks game ======
//? Grundy number also termed as Nimbers.
//! Grundy(n) => the game which the opposition will not play.
//? Grundy(n) = MEX( Grundy(n-picks[0]),Grundy(n-picks[1])...for all picks ).
//! MEX => Minimum exclusive non-Negative value from the list.
//** list inside MEX => the game which opposition will play.
//* Grundy(0) = 0 {always}

//? Grundy = 0 is a losing state.

#include "../header.h"

int MEX(set<int> &hashset)
{
    for (int i = 0; true; i++)
        if (hashset.count(i) == 0)
            return i;
}

int Grundy(int n, vi &picks)
{
    if (n == 0)
        return 0;
    set<int> hashset;
    for (int choice : picks)
        if (n - choice >= 0)
            hashset.insert(n - choice);
    return MEX(hashset);
}

void solve()
{
    int coins, n;
    cin >> coins >> n;
    vi picks(n);
    rarr(picks, 0, n);
    int grundy = Grundy(coins, picks);
    if (grundy == 0)
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

// 8
// 3
// 5 1 4