
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



