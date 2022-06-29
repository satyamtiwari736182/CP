// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner.
// 3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..).
// 4. Complete the body of printMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

#include "../header.h"

void printmazepathfreely(int n, int m, string ans)
{
    if (m < 0 || n < 0)
        return;
    if (n == 1 && m == 1)
    {
        cout << ans << " ";
        return;
    }
    for (int i = 1; i < n; i++)
        printmazepathfreely(n - i, m, "v" + to_string(i) + ans);
    for (int i = 1; i < n; i++)
        printmazepathfreely(n, m - i, "h" + to_string(i) + ans);
    for (int i = 1; i < n; i++)
        printmazepathfreely(n - i, m - i, "d" + to_string(i) + ans);
}

int main()
{
    cout << "hello!" << endl;
    printmazepathfreely(3, 3, "");

    return 0;
}

// 3 3