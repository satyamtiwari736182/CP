// 1. You are given a number n, the size of a chess board.
// 2. You are required to place n number of queens in the n * n cells of board such that no queen can
//      kill another.
// Note - Queens kill at distance in all 8 directions
// 3. Complete the body of printNQueens function - without changing signature - to calculate and
//      print all safe configurations of n-queens

// Use sample input and output to get more idea.

// Note -> The online judge can't force you to write the function recursively but that is what the spirit
//                of question is.

// Write recursive and not iterative logic. The purpose of the question is to aid learning recursion, branch and bound technique and not test you.

#include "../header.h"

// Solvin n-queen problem
void solve(vector<vi> &board, int row, vi &cols, vi &forward_diag, vi &backward_diag, string asf)
{

    if (row == board.size())
    {
        cout << asf << "\t";
        return;
    }

    for (int col = 0; col < board[0].size(); col++)
    {

        // Branch and Bound approach.  Here we are bounding the possible branches of recursion for placing the queen
        if (!cols[col] && !forward_diag[row + col] && !backward_diag[row - col + board.size() - 1])
        {
            board[row][col] = true;
            cols[col] = true;
            forward_diag[row + col] = true;
            backward_diag[row - col + board.size() - 1] = true;
            solve(board, row + 1, cols, forward_diag, backward_diag, asf + to_string(row) + "-" + to_string(col) + ", ");

            // backtracking
            board[row][col] = false;
            cols[col] = false;
            forward_diag[row + col] = false;
            backward_diag[row - col + board.size() - 1] = false;
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vector<vi> board;

    board.resize(n);
    for (int i = 0; i < n; i++)
        board[i].resize(n);

    vi cols(n);
    vi forward_diag(2 * n - 1);
    vi backward_diag(2 * n - 1);

    cout << "\n====================================\n";
    solve(board, 0, cols, forward_diag, backward_diag, "");
    cout << "\n====================================\n";

    return 0;
}

// 4