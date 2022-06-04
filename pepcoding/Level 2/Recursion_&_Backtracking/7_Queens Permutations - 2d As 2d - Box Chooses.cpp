// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the permutations in which n queens can be placed on the 
//      n * n chess-board. 

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't 
//                force you but the intention is to teach a concept. Play in spirit of the question.


#include "../header.h"
vector<vi> board;

void queenCombination(int row, int col, int qpsf, string asf, int total_queen, vi queen)
{
    if (row == total_queen)
    {
        if (qpsf == total_queen)
            cout << asf << endl;
        return;
    }

    int nrow = 0, ncol = 0;
    char sep = '\0';
    if (col == total_queen - 1)
    {
        nrow = row + 1, col = 0;
        sep = '\n';
    }
    else
    {
        nrow = row, ncol = col + 1;
        sep = ' ';
    }

    for (int i = 0; i < total_queen; i++)
        if (queen[i] == false)
        {
            queen[i] = true;
            queenCombination(nrow, ncol, qpsf + 1, asf + "q" + to_string(i + 1) + sep, total_queen, queen);
            queen[i] = false;
        }
        
    queenCombination(nrow, ncol, qpsf, asf + "_" + sep, total_queen, queen);
}

void solve()
{
    int n;
    cin >> n;
    vi queen(n);
    queenCombination(0, 0, 0, "", n, queen);
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