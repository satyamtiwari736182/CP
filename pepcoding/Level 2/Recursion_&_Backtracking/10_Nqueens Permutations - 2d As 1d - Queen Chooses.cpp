// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the permutations in which n queens (distinct) can be
//      placed on the n * n chess-board.
// 3. No queen shall be able to kill another.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
int board[100][100]; // flag => to check empty position

bool isQueenSafe(int cell, int length)
{
    int row = cell / length, col = cell % length;
    for (int i = row, j = col; i >= 0; i--) // vertically-up checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < length; i++) // vertically-down checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0; j--) // horizontally-left checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; j < length; j++) // horizontally-right checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // bacward-diagnol-up-part checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < length && j < length; i++, j++) // bacward-diagnol-down-part checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; i >= 0 && j < length; i--, j++) // forward-diagnol-up-part checks
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < length && j >= 0; i++, j--) // forward-diagnol-down-part checks
        if (board[i][j])
            return false;

    return true;
}

int cnt = 0;

void queenPermutation(int qpsf, int total_queen)
{
    if (qpsf == total_queen)
    {
        ::cnt++;
        for (int row = 0; row < total_queen; row++)
        {
            for (int col = 0; col < total_queen; col++)
            {
                if (board[row][col] != 0)
                    cout << "q" << board[row][col] << " ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int cell = 0; cell < total_queen * total_queen; cell++)
    {
        int row = cell / total_queen, col = cell % total_queen;
        if (board[row][col] == 0 && isQueenSafe(cell, total_queen) == true)
        {
            board[row][col] = qpsf + 1;
            queenPermutation(qpsf + 1, total_queen);
            board[row][col] = 0;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    Fill(board, 0);
    queenPermutation(0, n);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    cout << "\n====   " << cnt;
    return 0;
}
// 4