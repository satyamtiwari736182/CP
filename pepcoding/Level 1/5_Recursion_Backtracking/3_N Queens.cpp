// 1. You are given a number n, the size of a chess board.
// 2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
// Note - Queens kill at distance in all 8 directions
// 3. Complete the body of printNQueens function - without changing signature - to calculate and print all safe configurations of n-queens. Use sample input and output to get more idea.

#include "../header.h"

bool issafe(int board[][M], int n, int row, int col)
{

    for (int i = row - 1, j = col - 1; i > 0 && j > 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col + 1; i > 0 && j <= n; i--, j++)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col; i > 0 && j > 0; i--)
        if (board[i][j])
            return false;

    for (int i = row, j = col - 1; i > 0 && j > 0; j--)
        if (board[i][j])
            return false;

    return true;
}

void nqueen(int board[][M], int n, int row, string ans)
{

    if (row < 0)
        return;
    if (row == 0)
    {
        cout << ans << "\n";
        return;
    }

    for (int col = row - 1; col >= 0; col--)
    {
        if (board[row][col] == 0 && issafe(board, n, row, col) == 1)
        {
            board[row][col] = 1;
            nqueen(board, n, row - 1, to_string(row) + "-" + to_string(col) + " " + ans);
        }
        board[row][col] = 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    int board[N][M];
    memset(board, 0, sizeof(board));
    cout << "\n***********\n";
    nqueen(board, n, n, "");
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// 4