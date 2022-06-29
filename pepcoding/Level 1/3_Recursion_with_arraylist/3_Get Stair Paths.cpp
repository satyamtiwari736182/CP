// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
// 3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
// Use sample input and output to take idea about output.

#include "../header.h"

vector<string> getdownstair(int n)
{
    vector<string> temp;
    if (n < 0)
    {
        temp.pb("");
        return temp;
    }
    if (n == 0)
    {
        temp.pb("1");
        return temp;
    }
    auto temp1 = getdownstair(n - 1);
    auto temp2 = getdownstair(n - 2);
    auto temp3 = getdownstair(n - 3);
    for (auto itm : temp1)
        temp.pb("1" + itm);
    for (auto itm : temp2)
        temp.pb("2" + itm);
    for (auto itm : temp3)
        temp.pb("3" + itm);

    return temp;
}

int main()
{
    cout << "hello!" << endl;

    vector<string> seq;
    seq = getdownstair(3);
    parr(seq, seq.size());

    return 0;
}

// 3