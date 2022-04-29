// Three players Alice and Bob and Charlie are playing a game. There are two tables, on the first table, there are N heaps containing A[1],A[2].... A[n] coins, on the second table , there are M heaps containing B[1], B[2]... B[m] coins.
// Initially, Alice is playing at the first table and Bob is playing at the second table. The players take their turns in this order: Charlie, Alice, Bob, Charlie, etc.
// Bob and alice in their turn can remove as much coin as they want(min is 1) from any one pile of their respective tables. Whoever cannot remove any stone from a pile loses.
// Charlie does not play at any table. Instead, on his turn, he decides if Alice and Bob should keep playing at their respective tables or swap places.
// Alice and Charlie are buddies and they cooperate, playing in the optimal way that results in Alice's victory (if possible). Find out whether alice will win or bob.

#include "../header.h"

//! Not related with Nim-game

/*
case-1 (#coin)table_A  !=  (#coin)table_B
    always Alice wins.

case-2 (#coin)table_A  ==  (#coin)table_B
    i. Diff. structure
        Alice wins
    ii Same structure
        BoB wins
*/

void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    int table_A[n1], table_B[n2];
    rarr(table_A, 0, n1);
    rarr(table_B, 0, n2);

    int coin_A = 0, coin_B = 0;
    for (int coin : table_A)
        coin_A += coin;
    for (int coin : table_B)
        coin_B += coin;

    if (coin_A != coin_B)
        cout << "ALICE\n";
    else
    {
        sort(table_A, table_A + n1);
        sort(table_B, table_B + n2);
        int i = 0, j = 0;
        while (table_A[i] == 0)
            i++;
        while (table_B[j] == 0)
            j++;
        while (i < n1 && j < n2)
        {
            if (table_A[i] != table_B[j])
            {
                cout << "ALICE\n";
                return;
            }
            i++, j++;
        }

        cout << "BOB\n";
    }
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

// 6 7
// 24 6 10 56 9 1
// 0 6 24 1 9 56 10