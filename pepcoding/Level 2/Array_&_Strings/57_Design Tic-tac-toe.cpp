// Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves are allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
// Implement the TicTacToe class:

// TicTacToe(int n) Initializes the object the size of the board n.
// int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.

#include "../header.h"

int n, row[N] = {0}, col[N] = {0}, diag = 0, adiag = 0;
int move(int r, int c, int player)
{
    int inc = 1;
    if (player == 2)
        inc = -1;
    row[r] += inc, col[c] += inc;
    if (r == c)
        diag += inc;
    if (r + c == n - 1)
        adiag += inc;

    if (abs(row[r]) == n || abs(col[c]) == n || abs(diag) == n || abs(adiag) == n)
        return player;

    return 0;
}

void solve()
{
    cin >> n;
    cout << "--------------------" << endl;
    for (int i = 0; i < n * n; i++)
    {
        int r, c, player;
        cin >> r >> c >> player;
        int res = move(r, c, player);
        cout << res << "\n";
        if (res != 0)
            break;
    }
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
3
0 0 1
0 2 2
2 2 1
1 1 2
2 0 1
1 0 2
2 1 1
*/
