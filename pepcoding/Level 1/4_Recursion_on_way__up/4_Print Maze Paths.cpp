// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
// 3. Complete the body of pri tMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

#include "../header.h"

void printmazepath(int n, int m, string ans)
{
    if (m < 0 || n < 0)
        return;
    if (n == 1 && m == 1)
    {
        cout << ans << " ";
        return;
    }
    printmazepath(n - 1, m, "v" + ans);
    printmazepath(n, m - 1, "h" + ans);
    printmazepath(n - 1, m - 1, "d" + ans);
}

int main()
{
    cout << "hello!" << endl;
    printmazepath(3, 3, "");

    return 0;
}

// 2 2