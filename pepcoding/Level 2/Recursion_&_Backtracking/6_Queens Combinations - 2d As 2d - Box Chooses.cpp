// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the combinations in which n queens can be placed on the
//      n * n chess-board.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
vector<vi> board;
void queenCombination(int row, int col, int qpsf, int total_queen, string asf)
{
    if (row == total_queen)
    {
        if (qpsf == total_queen)
            cout << asf << endl;
        return;
    }

    int nrow = 0, ncol = 0;
    string yasf = "", nasf = "";
    if (col == total_queen - 1)
    {
        nrow = row + 1, col = 0;
        yasf = asf + "q\n";
        nasf = asf + "_\n";
    }
    else
    {
        nrow = row, ncol = col + 1;
        yasf = asf + "q ";
        nasf = asf + "_ ";
    }

    queenCombination(nrow, ncol, qpsf + 1, total_queen, yasf);
    queenCombination(nrow, ncol, qpsf, total_queen, nasf);
}

void solve()
{
    int n;
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; i++)
        board[i].resize(n);
    queenCombination(0, 0, 0, n, "");
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