// 1. You are given a number N, which represents the rows and columns of a 2-D matrix.
// 2. Matrix contains only three values -
//    a. Cell is empty.
//    b. Cell contains a cherry.
//    c. Cell contains a thorn and you can not pass through this cell.
// 3. You have to find the maximum number of cherries that you can collect following these rules :
//    a. You have to start from (0,0) and travel till (N-1,N-1) by moving right or down,
//     one step at a time.
//    b. After reaching (N-1,N-1), you have to come back to (0,0) by moving left or up,
//     one step at a time.

// Note -> If there is no valid path between the top-left cell and bottom-right cell, then no cherries can be collected.

#include "../header.h"

//************************** Approach 1: Brute Force Approach backtracking ***********************************
int maxCherry = 0;
void helper(int row, int col, vvi &arr, int ccsf)
{
    if (row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size() || arr[row][col] == -1)
        return;

    if (row == 0 && col == 0)
    {
        maxCherry = max(maxCherry, ccsf);
        return;
    }

    int cherry = arr[row][col];
    arr[row][col] = 0;
    helper(row - 1, col, arr, ccsf + cherry);
    helper(row, col - 1, arr, ccsf + cherry);
    arr[row][col] = cherry;
}

void cp1(int row, int col, vvi &arr, int ccsf)
{
    if (row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size() || arr[row][col] == -1)
        return;
    if (row == arr.size() - 1 && col == arr.size() - 1)
        helper(row, col, arr, ccsf);
    int cherry = arr[row][col];
    arr[row][col] = 0;
    cp1(row + 1, col, arr, ccsf + cherry);
    cp1(row, col + 1, arr, ccsf + cherry);
    arr[row][col] = cherry;
}
//****************************************************************************************************************

//************************** Approach 2: two person collecting from start point ***********************************

int dp[N][N][N][N];

int cp2(int row1, int col1, int row2, int col2, vvi &arr)
{
    if (row1 >= arr.size() || col1 >= arr[0].size() || row2 >= arr.size() || col2 >= arr[0].size() || arr[row1][col1] == -1 || arr[row2][col2] == -1)
        return INT_MIN;

    if (row1 == arr.size() - 1 && col1 == arr[0].size() - 1)
        return arr[row1][col1];

    if (dp[row1][col1][row2][col2] != 0)
        return dp[row1][col1][row2][col2];

    int cherry = 0;
    if (row1 == row2 && col1 == col2)
        cherry += arr[row1][col1];
    else
        cherry += arr[row1][col1] + arr[row2][col2];

    int c1 = cp2(row1 + 1, col1, row2 + 1, col2, arr); // v,v
    int c2 = cp2(row1 + 1, col1, row2, col2 + 1, arr); // v,h
    int c3 = cp2(row1, col1 + 1, row2 + 1, col2, arr); // h,v
    int c4 = cp2(row1, col1 + 1, row2, col2 + 1, arr); // h,h

    cherry += max(max(c1, c2), max(c3, c4));
    return dp[row1][col1][row2][col2] = cherry;
}

//************************** Approach 3: two person collecting from start point ***********************************

int dp2[N][N][N];

int cp3(int row1, int col1, int row2, vvi &arr)
{
    int col2 = row1 + col1 - row2;

    if (row1 >= arr.size() || col1 >= arr[0].size() || row2 >= arr.size() || col2 >= arr[0].size() || arr[row1][col1] == -1 || arr[row2][col2] == -1)
        return INT_MIN;

    if (row1 == arr.size() - 1 && col1 == arr[0].size() - 1)
        return arr[row1][col1];

    if (dp2[row1][col1][row2] != 0)
        return dp2[row1][col1][row2];

    int cherry = 0;
    if (row1 == row2 && col1 == col2)
        cherry += arr[row1][col1];
    else
        cherry += arr[row1][col1] + arr[row2][col2];

    int c1 = cp3(row1 + 1, col1, row2 + 1, arr); // v,v
    int c2 = cp3(row1 + 1, col1, row2, arr);     // v,h
    int c3 = cp3(row1, col1 + 1, row2 + 1, arr); // h,v
    int c4 = cp3(row1, col1 + 1, row2, arr);     // h,h

    cherry += max(max(c1, c2), max(c3, c4));
    return dp2[row1][col1][row2] = cherry;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vvi arr(n, vi(n));
    rmatrix(arr, n, n);
    cout << "\n---------------\n";
    // memset(dp, 0, sizeof(dp));
    fill(&dp2[0][0][0], &dp2[n][n][n] + 1, 0);
    // cp1(0, 0, arr, 0);
    cout << cp3(0, 0, 0, arr) << endl;
    //------------------------------------------------------
    cout << endl;
    return 0;
}

/*
3
0 1 -1
1 0 -1
1 1 1
*/
