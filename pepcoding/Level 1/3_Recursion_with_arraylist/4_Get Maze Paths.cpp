// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
// 3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

#include "../header.h"

vector<string> getdownmaze(int m, int n)
{
    vector<string> temp;
    if (m == 1 && n == 1)
    {
        temp.pb("");
        return temp;
    }
    temp.clear();
    if (m < 1 || n < 1)
        return temp;

    auto tempv = getdownmaze(m, n - 1);
    auto temph = getdownmaze(m - 1, n);
    for (auto itm : tempv)
        temp.pb("v" + itm);
    for (auto itm : temph)
        temp.pb("h" + itm);
    return temp;
}

int main()
{
    cout << "hello!" << endl;

    vector<string> seq;
    seq = getdownmaze(3, 3);
    parr(seq, seq.size());

    return 0;
}
// 3
// 3