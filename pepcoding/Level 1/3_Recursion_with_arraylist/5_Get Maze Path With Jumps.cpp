// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner.
// 3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..).
// 4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

#include "../header.h"

vector<string> getdownmazefreemove(int m, int n)
{
    vector<string> temp;
    if (m < 1 || n < 1)
        return temp;
    if (m == 1 && n == 1)
    {
        temp.pb("");
        return temp;
    }

    for (int i = 1; i < m; i++)
    {
        auto tempv = getdownmazefreemove(m - i, n);
        for (auto itm : tempv)
            temp.pb("v" + to_string(i) + itm);
    }

    for (int i = 1; i < n; i++)
    {
        auto temph = getdownmazefreemove(m, n - i);
        for (auto itm : temph)
            temp.pb("h" + to_string(i) + itm);
    }

    for (int i = 1; i < m; i++)
    {
        auto tempd = getdownmazefreemove(m - i, n - i);
        for (auto itm : tempd)
            temp.pb("d" + to_string(i) + itm);
    }

    return temp;
}

int main()
{
    cout << "hello!" << endl;

    vector<string> seq;
    seq = getdownmazefreemove(3, 3);

    parr(seq, seq.size());

    return 0;
}

// 2 2