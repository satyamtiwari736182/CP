// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the permutations in which n queens can be placed on the
//      n * n chess-board.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
vector<vi> board;
void queenPermutation(int curr_queen, int qpsf, int total_queen)
{
    if (curr_queen > total_queen)
    {
        pmatrix(board, total_queen, total_queen);
        cout << "---------\n";
        return;
    }
    for (int i = 0; i < total_queen; i++)
        for (int j = 0; j < total_queen; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = qpsf + 1;
                queenPermutation(curr_queen + 1, qpsf + 1, total_queen);
                board[i][j] = 0;
            }
        }
}

void solve()
{
    int n;
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; i++)
        board[i].resize(n);
    queenPermutation(1, 0, n);
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

// 2