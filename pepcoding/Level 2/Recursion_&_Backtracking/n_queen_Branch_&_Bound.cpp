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
        for (int j = 0; j < n; j++)
            board[i].resize(n);

    vi cols(n);
    vi forward_diag(2 * n - 1);
    vi backward_diag(2 * n - 1);

    cout << "\n====================================\n";
    solve(board, 0, cols, forward_diag, backward_diag, "");
    cout << "\n====================================\n";

    return 0;
}