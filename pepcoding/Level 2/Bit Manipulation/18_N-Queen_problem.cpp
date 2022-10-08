// 1. You are given a number n, the size of a chess board.
// 2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
//      Note - Queens kill at distance in all 8 directions
// 3. Complete the body of printNQueens function - without changing signature - to calculate and print all safe configurations of n-queens
//      Use sample input and output to get more idea.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.
//                Write recursive and not iterative logic. The purpose of the question is to aid learning recursion, branch and bound technique, bit manipulation
//                and not test you.

#include "../header.h"

void solve(vvi &board, int row, int cols, int forwarDiag, int revDiag, string asf)
{
    if (row == board.size())
    {
        cout << asf << endl;
        return;
    }

    for (int col = 0; col < board[0].size(); col++)

        if ((cols & (1 << col)) == false &&
            (forwarDiag & (1 << (row + col))) == false &&
            (revDiag & (1 << (row - col + board.size() - 1))) == false)
        {

            board[row][col] = true;
            cols ^= (1 << col);
            forwarDiag ^= (1 << (row + col));
            revDiag ^= (1 << (row - col + board.size() - 1));

            solve(board, row + 1, cols, forwarDiag, revDiag, asf + to_string(row) + "-" + to_string(col) + ", ");

            board[row][col] = false;
            cols ^= (1 << col);
            forwarDiag ^= (1 << (row + col));
            revDiag ^= (1 << (row - col + board.size() - 1));
        }
}

void solve2(int nxn, int row, int cols, int forwarDiag, int revDiag, string asf)
{
    if (row == nxn)
    {
        cout << asf << endl;
        return;
    }

    for (int col = 0; col < nxn; col++)

        if ((cols & (1 << col)) == false &&
            (forwarDiag & (1 << (row + col))) == false &&
            (revDiag & (1 << (row - col + nxn - 1))) == false)
        {

            // board[row][col] = true;
            cols ^= (1 << col);
            forwarDiag ^= (1 << (row + col));
            revDiag ^= (1 << (row - col + nxn - 1));

            solve2(nxn, row + 1, cols, forwarDiag, revDiag, asf + to_string(row) + "-" + to_string(col) + ", ");

            // board[row][col] = false;
            cols ^= (1 << col);
            forwarDiag ^= (1 << (row + col));
            revDiag ^= (1 << (row - col + nxn - 1));
        }
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vvi board(n, vi(n));
    cout << "\n========================================\n";
    solve(board, 0, 0, 0, 0, "");
    cout << "\n========================================\n";

    return 0;
}