// Two players Alice and Bob are playing a game. They have 2 pile's with n1 and n2 coins in it.
// They can pick only allowed numbers of coins from any one pile at a time given in an array picks.
// Alice goes first and they take alternate turns.
// The player who picks the last coin is the winner. Can you find out the winner.

//? Grundy number also termed as Nimbers.
//! Grundy(n) => the game which the opposition will not play.
//? Grundy(n) = MEX( Grundy(n-picks[0]),Grundy(n-picks[1])...for all picks ).
//! MEX => Minimum exclusive non-Negative value from the list.
//** list inside MEX => the game which opposition will play.
//* Grundy(0) = 0 {always}

//? Grundy = 0 is a losing state.

/*



?   g(v)=mex({g(u)|(v,u) exists})
Then a state v is winning for the player who is about to make a move, iff g(v)>0. Additionally, if we consider two games played in parallel such that each player first gets to choose a game on which to make a move, and then chooses any valid move in that game, then the grundy number for a pair of states (u,v) from different games is

?     g(u)⊕g(v),
* where ⊕ represents the bitwise xor.

 These facts together are known as the Sprague-Grundy theorem, and there are some great blogs dealing with justifications and applications of these ideas, for example this one. But ok, you already knew these things, now I will explain a slight generalization to this concept that could be useful in solving some problems.

*/

#include "../header.h"

int MEX(set<int> &hashset)
{
    for (int i = 0; true; i++)
        if (hashset.count(i) == 0)
            return i;
}

void solve()
{
    int n1, n2, n;
    cin >> n1 >> n2 >> n;
    vi picks(n);
    int mx = max(n1, n2);
    rarr(picks, 0, n);

    int dp[mx];
    //? ====== Nimbers using dp =======
    for (int i = 1; i <= mx; i++)
    {
        set<int> hashset;
        for (int val : picks)
            if (val <= i)
                hashset.insert(i - val);
        dp[i] = MEX(hashset);
    }
    //==================================
    int grundy1 = dp[n1];
    int grundy2 = dp[n2];

    int result = grundy1 ^ grundy2;

    if (grundy1 == grundy2)
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

// 4 3
// 3
// 1 4 2