// 1. You are given a number.
// 2. You have to print all the numbers from 1 to n in lexicographical order.

// Note -> Check out the question video and write the recursive code as it is intended without 
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

void dfs(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    for (int j = 0; j < 10; j++)
        dfs(10 * i + j, n);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
        dfs(i, n);
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
/*
14
*/