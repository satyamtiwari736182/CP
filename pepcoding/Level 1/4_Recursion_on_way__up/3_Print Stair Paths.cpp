// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
// 3. Complete the body of printStairPaths function - without changing signature - to print the list of all paths that can be used to climb the staircase up.
// Use sample input and output to take idea about output.

#include "../header.h"

void printstair(int n, string ans)
{
    if (n < 0)
        return;
    if (n == 0)
    {
        cout << ans << " ";
        return;
    }
    for (int i = 1; i <= 3; i++)
        printstair(n - i, ans + to_string(i));
}

int main()
{
    cout << "hello!" << endl;
    printstair(5, "");

    return 0;
}

// 3